#include <stdio.h>
#include "estruturas/vector.h"
#include "estruturas/int_linked_list.h"

#define TESTE teste_int_linked_list01

#define DEBUG

#ifdef DEBUG
#define LOGF(...) printf(__VA_ARGS__)
#else
#define LOGF(...)
#endif


// ------------------------
//  TESTES E DEMONSTRACOES
// ------------------------

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
        printf("v[%d]: %d\n", input, *(int*)get_elem_at(v, input));
    }

    return 0;
}

int teste_vetor_dinamico_ordem() {
    Vector* v1 = NEW_VECTOR(int);
    append_array_to_vec(v1, (int[]){1, 2, 3, 4, 5}, 5);
    print_vector_int(v1, "v1");

    Vector* v2 = NEW_VECTOR(int);
    append_array_to_vec(v2, (int[]){10, 9, 8, 7, 6}, 5);
    print_vector_int(v2, "v2");

    Vector* v3 = NEW_VECTOR(int);
    append_array_to_vec(v3, (int[]){1, 1, 2, 3, 2}, 5);
    print_vector_int(v3, "v3");

    Vector* v4 = NEW_VECTOR(int);
    append_array_to_vec(v4, (int[]){21, 21, 21, 21, 21}, 5);
    print_vector_int(v4, "v4");

}

int teste_int_linked_list01() {
    Node* h1 = new_node(5);
    push_back_value(h1, 2);
    push_back_value(h1, 7);
    push_back_value(h1, 5);

    print_list(h1, true);
    return 0;
}

// --------
//   MAIN
// --------

int main() {
    return TESTE();
}
