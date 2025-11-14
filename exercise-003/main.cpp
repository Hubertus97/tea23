#include <fmt/chrono.h>
#include <fmt/format.h>

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
        /* code */
    }


    return 0; /* exit gracefully*/
}
