#include "int_linked_list.h"
#include <stdio.h>

// FLAGS DE PRINT
#define FIRST_PRINT_FLAG -1
#define PRINT_NONE 0 
#define LAST_PRINT_FLAG 1

Node* new_node(int val) {
    Node* newNode = malloc(sizeof(Node));
    newNode->next = NULL;
    return newNode;
}

// Libera recursivamente a memória de todos os nós de uma lista
void free_list(Node* head) {
    if (head == NULL)
        return;
    free_list(head->next);
    free(head);
}

// Versão iterativa
void it_free_list(Node* head) {
    if (head == NULL) {
        return;
    }

    Node* cur = head;
    Node* next = NULL;
    while (cur != NULL) {
        next = head->next;
        free(cur);
        cur = next;
    }
}

void print_list(Node* head, bool firstPrint) {
    if (head == NULL)
        return;
    if (firstPrint)
        printf("( ");
    printf("%d ", head->data);
    print_list(head->next, false);
    if (firstPrint)
        printf(")");
}