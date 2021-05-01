#ifndef LAB_LIST_H
#define LAB_LIST_H

#include<stdio.h>
#include<stdlib.h>


typedef struct Node {
    char value;
    struct Node *next;
} Node;

void push(Node **head, char data);
char pop(Node **head);
Node* getLast(Node *head);
void pushBack(Node *head, char value);
Node* getLastButOne(Node* head);
void popBack(Node **head);
void printLinkedList(const Node *head);
int Len(Node *head);

#endif //LAB_LIST_H
