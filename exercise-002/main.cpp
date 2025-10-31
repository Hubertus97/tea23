#include <fmt/chrono.h>
#include <fmt/format.h>

#include <fmt/format.h>
#include <cstdlib>
#include <cstring>

int main() {
    char *ghost = (char*)malloc(8);
    strcpy(ghost, "evil");
    free(ghost);
    
}

fmt::println("{}", ghost);