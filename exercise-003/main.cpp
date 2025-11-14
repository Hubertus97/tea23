#include <fmt/chrono.h>
#include <fmt/format.h>
#include <iostream>

enum class GarageState{
    FahreHoch,
    FahreRunter,
    StopAufDemWegNachOben,
    StopAufDemWegNachUnten,
    GaragenTorOffen,
    GaragenTorZu,
};


auto main(int argc, char** argv) -> int
{
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", argv[0]);

    GarageState CurrentState = GarageState::FahreHoch;

    while (true)
    {
        // --- Simulation der Eingabe ---
        // (Wir lesen die Eingaben am Anfang jedes Schleifendurchlaufs)
        fmt::println("Drücke Enter für 'Taste', 'o' für 'Oben', 'u' für 'Unten'");
        
        char input = std::cin.get();
        if(input != '\n') { // Puffer leeren, falls nicht nur Enter gedrückt wurde
            std::cin.ignore(10000, '\n'); 
        }
        // --- Ende Simulation ---


        // --- Start der State Machine Logik ---
        switch (CurrentState)
        {
        case GarageState::FahreHoch:
            fmt::println("Tor fährt hoch");
            if (input == '\n')
            {
                CurrentState = GarageState::StopAufDemWegNachOben;
            }
            else if (input == 'o')
            {
                CurrentState = GarageState::GaragenTorOffen;
            }
            break;

        case GarageState::FahreRunter:
            fmt::println("Tor fährt runter");
            if (input == '\n')
            {
                CurrentState = GarageState::StopAufDemWegNachUnten;
            }
            else if (input == 'u')
            {
                CurrentState = GarageState::GaragenTorZu;
            }
            break;

        case GarageState::GaragenTorOffen:
            fmt::println("Tor ist offen");
            if (input == '\n')
            {
                CurrentState = GarageState::FahreRunter;
            }
            break;

        case GarageState::GaragenTorZu:
            fmt::println("Tor ist zu");
            if (input == '\n')
            {
                CurrentState = GarageState::FahreHoch;
            }
            break;

        case GarageState::StopAufDemWegNachOben:
            fmt::println("Stop auf dem Weg nach oben");
            if (input == '\n')
            {
                CurrentState = GarageState::FahreRunter;
            }
            break;

        case GarageState::StopAufDemWegNachUnten:
            fmt::println("Stop auf dem Weg nach unten");
            if (input == '\n')
            {
                CurrentState = GarageState::FahreHoch;
            }
            break;
        
        default:
            break;
        }
    }


    return 0; /* exit gracefully*/
}
