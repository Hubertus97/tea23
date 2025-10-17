#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

int y = 5;
void changeValueByParameter(int value){
    value = 99;
    fmt::println("Wert von y am Ende innerhalb der Funktion: {}",y);
    fmt::println("Wert von value am Ende innerhalb der Funktion: {}",value);
};

void ChangeValueByPointer(int* pointer){
    *pointer = 77;
    fmt::println("Wert von Pointer:{}",y);
    fmt::println("Wert von Pointer:{}",*pointer);
};

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
    
    *p = 42;

    fmt::println("Wert von x:{}",x);

    fmt::println("Wert auf den p zeigt:{}",*p);


    fmt::println("------Aufgabe2------");

    double* ZeigerAufDouble = new double(3.1415);
    fmt::println("Wert von ZeigerAufDouble:{}, Adresse im Heap von dem Double Wert 3.1415:{}",*ZeigerAufDouble,fmt::ptr(ZeigerAufDouble));
    fmt::println("Adresse an dem der Pointer gespeichert ist der auf die Adresse des Double Werts zeigt:{}",fmt::ptr(&ZeigerAufDouble));
    delete ZeigerAufDouble;

    fmt::println("------Aufgabe3------");

    fmt::println("Wert von y vor Funktion:{}",y);
    changeValueByParameter(y);
    fmt::println("Wert von y nach der Funktion:{}",y);

    fmt::println("Wert von y vor Pointer Funktion:{}",y);
    ChangeValueByPointer(&y);
    fmt::println("Wert von y nach Pointer Funktion:{}",y);

    return 0; /* exit gracefully*/
}
