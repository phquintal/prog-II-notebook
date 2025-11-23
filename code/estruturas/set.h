#include <stdlib.h>
#include <stdbool.h>

typedef struct Set Set;

Set* new_set();

void free_set(Set* S);

bool value_in_set(Set* S, float x);

void add_to_set(Set* S);

void remove_from_set(Set* S);

void print_set(Set* S);

unsigned get_set_size(Set* S);

Set* set_union(Set* A, Set* B);
