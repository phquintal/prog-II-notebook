#include "vector.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define CAPACIDADE_INICIAL 4

#define DEBUG
#include "debug.h"

struct Vector {
    unsigned n;
    unsigned capacity;
    unsigned elemSize;
    void* data;
};

Vector* new_vector(unsigned elemSize) {
    Vector* newVec = malloc(sizeof(Vector));
    newVec->elemSize = elemSize;
    LOGF("DEBUG: elemSize %d\n", newVec->elemSize);
    newVec->capacity = CAPACIDADE_INICIAL;
    newVec->n = 0;
    newVec->data = malloc(newVec->capacity * newVec->elemSize);
    return newVec;
}

void free_vector(Vector* v) {
    free(v->data);
    free(v->data);
}

void push_back(Vector* v, void* elem) {
    LOGF("[DEBUG] Inserindo no indice %d\nv->capacity: %d\n", v->n, v->capacity);
    if (v->n >= v->capacity) {
        LOGF("[DEBUG] Expandindo vetor para ");
        v->capacity *= 2;
        v->data = realloc(v->data, v->capacity * v->elemSize);
        LOGF("%d bytes\n", v->capacity);
    }

    void* insertion_point = (char*)v->data + v->n * v->elemSize;
    LOGF("[DEBUG] *%p = %d\n", insertion_point, *(int*)elem);

    memcpy(insertion_point, elem, v->elemSize);
    v->n++;
}

void* elem_at(Vector* v, int index) {
    LOGF("Acessando elemento de índice %d\n", index);
    assert(index < v->n);

    char* elemptr = (char*)v->data + index * v->elemSize;
    LOGF("Ponteiro retornado: %p\n", elemptr);
    return elemptr; 
}

unsigned get_vector_size(Vector* v) {
    return v->n;
}
