#include "array2.h"


array* array_create(string* keys, string* data, size_t count){
    array* arr = malloc(sizeof(array));
    arr->capacity = (arr->len = count) * 2;

    arr->array = calloc(arr->capacity, sizeof(node));
    for (int i = 0; i < count; ++i) {
        arr->array[i].key = keys[i];
        arr->array[i].data = data[i];
    }
    return arr;
}

void array_push_back(array* arr, node n){
    if(arr->capacity == arr->len){
        arr->capacity *= 2;
        arr->array = realloc(arr->array, arr->capacity);
    }
    arr->array[arr->len] = n;
    arr->len++;
}

node* array_back(array* arr){
    if(arr->len)
        return arr->array + arr->len-1;
    return NULL;
}

void array_pop_back(array* arr){
    if(arr->len) arr->len--;
}


void array_free(array * l){
    free(l->array);
    free(l);
}

void array_node_swap(node* arr, size_t ind1, size_t ind2){
    node tmp = arr[ind1];
    arr[ind1] = arr[ind2];
    arr[ind2] = tmp;
}

char array_hoar_quick_sort_partition(node* arr, size_t low, size_t high){
    char pivot = (arr[low].key[0] + arr[high].key[0]) / 2;
    
    size_t i = low-1 ,j = high+1;
    while(true){
        
        
        do{
            i++;
        } while (arr[i].key[0] < pivot);

        do {
            j--;
        } while (arr[j].key[0] > pivot);
        if(i >= j) return j;

        array_node_swap(arr, i, j);
    }
}

void _array_quick_sort(node* arr, size_t low, size_t high){
    if(low < high){
        char pivot = array_hoar_quick_sort_partition(arr, low, high);
        _array_quick_sort(arr, low, pivot);
        _array_quick_sort(arr, pivot+1, high);
    }
}

void array_quick_sort(array* arr){
    _array_quick_sort(arr->array, 0, arr->len-1);
}

void array_print(array *arr){
    for (size_t i = 0; i < arr->len; ++i) {
        printf("%c%c%c%c  %s ", arr->array[i].key[0], arr->array[i].key[1], arr->array[i].key[2], arr->array[i].key[3], arr->array[i].data);
    }
    puts("");
}

void array_shuffle(array *arr){
    for (size_t i = 0; i < arr->len-1; ++i) {
        for (size_t j = i+1; j < arr->len; ++j) {
            if((unsigned long)random() & 1u){
                array_node_swap(arr->array, i, j);
            }
        }
    }
}

void array_reverse(array *arr){
    for (size_t i = 0; i < arr->len/2; ++i) {
        array_node_swap(arr->array, i, arr->len - i - 1);
    }
}

