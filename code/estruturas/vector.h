#pragma once

#include <stdlib.h>

typedef struct Vector Vector;

// Aloca um novo vetor e retorna um ponteiro para ele
Vector* new_vector(unsigned elemSize);
#define NEW_VECTOR(t) new_vector(sizeof(t));

// Libera a memória que está sendo usada por um vetor
void free_vector(Vector* v);

// Adiciona um novo elemento no fim do vetor
void push_back(Vector* v, void* elem);

void remove_elem(Vector* v, void* elem); 

// Retorna um ponteiro para os dados do elemento de índice `index`
void* elem_at(Vector* v, int index);


// ----------------------
//   Funções Adicionais
// ----------------------

void increase_vector_capacity(Vector* v);
unsigned get_vector_size(Vector* v);