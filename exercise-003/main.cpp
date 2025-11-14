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
            if (input == '\n')
            {
                CurrentState = GarageState::StopAufDemWegNachOben;
                fmt::println("Stop Auf dem Weg nach oben");
            }
            else if (input == 'o')
            {
                CurrentState = GarageState::GaragenTorOffen;
                fmt::println("Garagentor offen");
            }
            else
            {
                fmt::println("Tor fährt hoch");
            }
            break;

        case GarageState::FahreRunter:
            if (input == '\n')
            {
                CurrentState = GarageState::StopAufDemWegNachUnten;
                fmt::println("Stop auf dem Weg nach unten");
            }
            else if (input == 'u')
            {
                CurrentState = GarageState::GaragenTorZu;
                fmt::println("Garagentor zu");
            }
            else
            {
                fmt::println("Tor fährt runter");
            }
            
            break;

        case GarageState::GaragenTorOffen:
            if (input == '\n')
            {
                CurrentState = GarageState::FahreRunter;
                fmt::println("Tor fährt runter");
            }
            break;

        case GarageState::GaragenTorZu:
            if (input == '\n')
            {
                CurrentState = GarageState::FahreHoch;
                fmt::println("Fahre hoch");
            }
            break;

        case GarageState::StopAufDemWegNachOben:
            if (input == '\n')
            {
                CurrentState = GarageState::FahreRunter;
                fmt::println("Fahre runter");
            }
            break;

        case GarageState::StopAufDemWegNachUnten:
            if (input == '\n')
            {
                CurrentState = GarageState::FahreHoch;
                fmt::println("Fahre hoch");
            }
            break;
        
        default:
            break;
        }
    }


    return 0; /* exit gracefully*/
}
