#include "vector.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define CAPACIDADE_INICIAL 4

// #define DEBUG
#include "helper/debug.h"

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
    assert(v != NULL);
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

void* get_elem_at(Vector* v, int index) {
    LOGF("Acessando elemento de índice %d\n", index);
    assert(index < v->n);

    char* elemptr = (char*)v->data + index * v->elemSize;
    LOGF("Ponteiro retornado: %p\n", elemptr);
    return elemptr; 
}

unsigned get_vector_size(Vector* v) {
    return v->n;
}

#pragma region
// AVISO: A função abaixo foi implementada por teimosia minha, mas provavelmente não vamos ter que implementar nada tão complicado esse semestre.
// O uso de `memcmp` é para comparar blocos de memória "crus" e retornar a diferença entre eles.
// Nessa implementação, está servindo para dizer em qual ordem o vetor está, mesmo sem saber de que tipo ele é de antemão.
// Ter uma função para isso ajuda em fazer funções de busca binária mais seguras, mas não é algo que eu ache que seja importante pra matéria.

// Usa a função `memcmp` para comparar os blocos de memória de cada elemento do vetor já que não se sabe o tipo de dado guardado nele até então
int get_vector_order(Vector* v) {
    assert(v != NULL);

    // Todos os elementos de um vetor de só um elemento são iguais
    if (v->n <= 1) return TUDO_IGUAL;

    int order = TUDO_IGUAL;
    for (int i = 0; i < v->n-1; i++) {
        
        // A função `memcpm` recebe dois ponteiros void e o tamanho do bloco a ser comparado.
        // Ela retorna a diferença lexográfica entre os dois blocos, que então é guardada na variável `compare`
        int compare = memcmp(get_elem_at(v, i), get_elem_at(v, i+1), v->elemSize);

        // Se compare for menor que 0, o valor do primeiro bloco é menor que o do segundo. Então a ordem é crescente
        // Se não, se compare for
        if (compare < 0)
            order = ORDEM_CRESCENTE; 
        else if (compare > 0)
            order = ORDEM_DECRESCENTE;
        else
            order = TUDO_IGUAL;

        // O loop continua até que se encontrem dois elementos em que um não é igual ao outro.
        if (order != TUDO_IGUAL) break;
    }
    
    // Se a ordem ainda for a mesma, quer dizer que todas as comparações dentro do vetor deram que os elementos são iguais.
    if (order == TUDO_IGUAL) return TUDO_IGUAL;

    for (int i = 0; i < v->n-1; i++) {
        if (memcmp(get_elem_at(v, i), get_elem_at(v, i+1), v->elemSize) != order) return SEM_ORDEM;
    }
    return order;
}
#pragma endregion

void append_array_to_vec(Vector* v, void* arr, unsigned n) {
    for (int i = 0; i < n; i++) {
        push_back(v, (char*)arr + i * v->elemSize);
    }
}

void print_vector_int(Vector* v, const char* vecname) {
    printf("%s: ", vecname);
    for (int i = 0; i < get_vector_size(v); i++) {
        printf("%d ", *(int*)get_elem_at(v, i));
    }
    printf("\n");
}