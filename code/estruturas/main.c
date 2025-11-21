#include <stdio.h>
#include "vector.h"

#define DEBUG

#ifdef DEBUG
#define LOGF(...) printf(__VA_ARGS__)
#endif
int teste_vetor_dinamico01() {
    Vector* v = NEW_VECTOR(int);


    unsigned i = 0;
    while (1) {
        int input = -1;
        printf("Digite um numero:\n");
        scanf("%d", &input);
        if (input == -1) break;
        LOGF("Escaneado\n");
        push_back(v, &input);
        i++;
        printf("v[%d]: %d inserido\n", get_vector_size(v) - 1, input);
    }

    printf("Seu vetor tem %d elementos\n", get_vector_size(v));
    while (1) {
        int input = -1;
        printf("Insira o indice do elemento (0 - %d) ou -1 para sair:\n", get_vector_size(v) - 1);
        scanf(" %d", &input);
        if (input == -1)
            break;
        LOGF("[DEBUG] v[%d]\n", input);
        printf("v[%d]: %d\n", input, *(int*)elem_at(v, input));
    }

    return 0;
}

int main() {
    return teste_vetor_dinamico01();
}
