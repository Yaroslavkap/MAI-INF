#ifndef LAB_ARRAY_H
#define LAB_ARRAY_H

#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

typedef char* string;

typedef struct node{
    string key;
    string data;
} node;

typedef struct array{
    node *array;
    size_t len, capacity;
} array;

array* array_create(string* keys, string* data, size_t count);
void array_push_back(array* arr, node n);
node* array_back(array* arr);
void array_pop_back(array* arr);
void array_free(array* l);

void array_node_swap(node* arr, size_t ind1, size_t ind2);

void array_print(array *arr);

void array_quick_sort(array* arr);
void array_shuffle(array *arr);
void array_reverse(array *arr);

#endif //LAB_ARRAY_H

