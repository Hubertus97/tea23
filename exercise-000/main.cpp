#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

int main(int argc, char **argv) {

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", tea::PROJECT_NAME);

    /*for (int i = 0 ; i< argc; i++){
        fmt::println("argc:{}, argument{} (Adresse:{})",i, argv[i],fmt::ptr(argv[i]));
    }*/

    fmt::println("------Aufgabe1------");

    int x =10;
    int* p = &x;

    fmt::println("Wert von x:{}, Adresse von x:{}",x,fmt::ptr(&x));
    
    fmt::println("Wert auf den Zeiger p zeigt:{}",*p);

    fmt::println("Adresse die in p gespeichert ist:{}",fmt::ptr(p));

    return 0; /* exit gracefully*/
}
