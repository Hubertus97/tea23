#include "vector.hpp"

void vector_init(Vector_t* vec){
    vec -> data = new unsigned int [4];
    vec -> size = 0;
    vec ->capacity = 4;
}

void vector_clear(Vector_t* vec){
    delete[] vec -> data;
    vec -> data = nullptr;
    vec -> size = 0;
    vec -> capacity = 0;
}