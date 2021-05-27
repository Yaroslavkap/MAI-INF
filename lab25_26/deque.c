#include "deque.h"
#include <stdlib.h>

void deque_create(deque *a)
{
    a->elements = malloc(sizeof(int));
    a->capasity = 0;
    a->number_of_elements = 0;
}

void push_front(deque *a, int b)
{ 
    if(a->number_of_elements == a->capasity) {
        resize(a);
    }
    int tmp1, tmp2;
    tmp1 = b;
    for(int i = 0; i < a->number_of_elements + 1; i++) {
        tmp2 = a->elements[i];
        a->elements[i] = tmp1;
        tmp1 = tmp2;
    }
    a->number_of_elements++;
}

void push_back(deque *a, int b)
{ 
    if (a->number_of_elements == deque_size(a)) {
        resize(a);
    }
    a->elements[a->number_of_elements] = b;
    a->number_of_elements++;
}

void pop_back(deque *a)
{
    if (a->number_of_elements > 0) {
        for(int i; i < size(a); i++) {
            a->elements[i + 1] = a->elements[i];
        }
        a->number_of_elements--;
        a->capasity--;
    }
}

void pop_front(deque *a)
{
    if (a->number_of_elements > 0) {
        a->elements[0] = 0;
        for(int i = 0; i < deque_size(a); i++) {
            a->elements[i] = a->elements[i + 1];
        }
        a->number_of_elements--;
        a->capasity--;
    }
}

int first_front(deque* a)
{
    return a->elements[0];
}

int first_back(deque* a)
{
    return a->elements[a->number_of_elements - 1];
}

int empty(deque *a)
{
    if (a->number_of_elements == 0) {
        return 1;
    } else {
        return 0;
    }
}

void resize(deque *a)
{
    a->capasity++;
    a->elements = realloc(a->elements, a->capasity * sizeof(int));
}

int size(deque* a)
{
    return a->number_of_elements;
}

int deque_size(deque *a)
{
    return a->capasity;
}

deque* reverse(deque* a)
{
    deque* b;
    deque_create(b);
    while (!empty(a)) {
        push_front(b, first_front(a));
        pop_front(a);
    }
    return b;
}


void print(deque* a)
{
    int i;
    int val;
    
    
    for (i = 0; i < deque_size(a); i++)
	{
		val = a->elements[i];

		printf("%d", val);
	}
	printf("\n");
}



void rev(deque* a)
{
    int j = 0;
    for(int i = 0; i < deque_size(a) / 2; i++) {
        j = deque_size(a) - i;
        int x = a->elements[i];
        int y = a->elements[j];
        
        a->elements[i] = y;
        a->elements[j] = x;
    }
    
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void qs(deque* a, int first, int last)
{
    int i = first, j = last, x = a->elements[(first + last) / 2];
  
    do {
        while (a->elements[i] < x) i++;
        while (a->elements[j] > x) j--;
  
        if (i <= j) {
            if (a->elements[i] > a->elements[j]) {
                swap(&a->elements[i], &a->elements[j]);
            }
            i++;
            j--;
        }
    } while (i <= j);
  
    if (i < last)
        qs(a, i, last);
    if (first < j)
        qs(a, first, j);
}


void conc(deque* a, deque* b)
{
    int x = deque_size(a);
    int y = deque_size(b);
    a->capasity = a->capasity + b->capasity;
    a->number_of_elements = a->number_of_elements + b->number_of_elements;
    for(int i = 0; i < y; i++) {
       a->elements[x + i] = b->elements[i];
    }
}






