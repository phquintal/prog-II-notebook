#include <stdlib.h>
#include <stdbool.h>

typedef struct Node Node;
struct Node {
    int data;
    Node* next;
};

Node* new_node(int val);

void free_list(Node* head);

void print_list(Node* head);

// Insere um novo nó na frente da lista se `back` é `false` ou no final da lista se `back` é `true`
Node* push_node(Node* head, Node* node, bool back);

// Inicializa um nó com o valor `val` e o insere na frente da lista
#define push_front_value(head, val) push_node(head, new_node(val), false)

// Inicializa um nó com o valor `val` e o insere no final da lista
#define push_back_value(head, val) push_node(head, new_node(val), true)

Node* search_value(Node* head, int val);

Node* remove_node(Node* head, Node* node);
#define remove_value(head, val) remove_value(head, search_value(head, val))
