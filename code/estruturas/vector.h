#pragma once

#include <stdlib.h>
#include <stdbool.h>

// Valores de ordem do vetor retornados pela função `get_vector_order`
#define ORDEM_CRESCENTE -1
#define TUDO_IGUAL 0
#define ORDEM_DECRESCENTE 1
#define SEM_ORDEM 2

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
void* get_elem_at(Vector* v, int index);


// ----------------------
//   Funções Adicionais
// ----------------------

// Funções que não fazem parte da interface original mostrada nas aulas, mas que implementei como utilidades

unsigned get_vector_size(Vector* v);

bool get_vector_order(Vector* v);

// Insere cada elemento de um vetor estático em um vetor dinâmico
void append_array_to_vec(Vector* v, void* arr, unsigned n);

void print_vector_int(Vector* v, void* arr, unsigned n);
