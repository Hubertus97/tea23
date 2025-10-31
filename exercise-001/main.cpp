#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

int globalVar = 1;
int globalVarNullwert = 0;
int globalVarOhneWert;

int static staticglobalVar = 1;
int static staticglobalVarNullwert = 0;
int static staticglobalVarOhneWert;

int const test = 1;
int const testnullwert = 0;

void WertUndAdresseVonVar(const int& Variable){
        fmt::println("Wert von Var:{}. Adresse von Var: {}",Variable, fmt::ptr(&Variable));    
}

void foo(){fmt::print("Hello from foo!\\n");
}

int main(int argc, char **argv) {

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", tea::PROJECT_NAME);

    /* INSERT YOUR CODE HERE */

    fmt::println("globalVar:");
    WertUndAdresseVonVar(globalVar);

    fmt::println("globalVarNullwert:");
    WertUndAdresseVonVar(globalVarNullwert);
    
    fmt::println("globalVarOhneWert:");
    WertUndAdresseVonVar(globalVarOhneWert);
    
    fmt::println("-----STATIC-----");
    
    fmt::println("staticglobalVar:");
    WertUndAdresseVonVar(staticglobalVar);

    fmt::println("staticglobalVarNullwert:");
    WertUndAdresseVonVar(staticglobalVarNullwert);
    
    fmt::println("staticglobalVarOhneWert:");
    WertUndAdresseVonVar(staticglobalVarOhneWert);

    fmt::println("-----CONST-----");
    
    fmt::println("constglobalVar:");
    WertUndAdresseVonVar(test);

    fmt::println("constglobalVarNullwert:");
    WertUndAdresseVonVar(testnullwert);

    fmt::println("-----LOCAL-----");

    int localVar = 2;
    int static localStaticVar = 3;
    int const localConstVar = 4;

    fmt::println("localVar:");
    WertUndAdresseVonVar(localVar);

    fmt::println("localStaticVar:");
    WertUndAdresseVonVar(localStaticVar);

    fmt::println("localConstVar:");
    WertUndAdresseVonVar(localConstVar);

    fmt::println("-----HEAP-----");

    int* heapVar = new int(3);

    fmt::println("heapVar Wert:{}. heapVar Adresse:{}.", *heapVar, fmt::ptr(heapVar));

    delete heapVar;

    fmt::print("Adresse von foo: {}\\n", fmt::ptr(&foo));

    /*fmt::println("staticglobalVarOhneWert:");
    WertUndAdresseVonVar(abc, &abc);*/

    return 0; /* exit gracefully*/
}
