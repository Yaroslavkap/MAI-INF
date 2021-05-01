#include<stdio.h>
#include<stdlib.h>
#include "list.h"



void push(Node **head, char data) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = data;
    tmp->next = (*head);
    (*head) = tmp;
}

char pop(Node **head) {
    Node* prev = NULL;
    char val;
    if (head == NULL) {
        exit(-1);
    }
    prev = (*head);
    val = prev->value;
    (*head) = (*head)->next;
    free(prev);
    return val;
}





Node* getLast(Node *head) {
    if (head == NULL) {
        return NULL;
    }
    while (head->next) {
        head = head->next;
    }
    return head;
}


void pushBack(Node *head, char value) {
    Node *last = getLast(head);
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = value;
    tmp->next = NULL;
    last->next = tmp;
}


Node* getLastButOne(Node* head) {
    if (head == NULL) {
        exit(-2);
    }
    if (head->next == NULL) {
        return NULL;
    }
    while (head->next->next) {
        head = head->next;
    }
    return head;
}


void popBack(Node **head) {
    Node *lastbn = NULL;
    //Получили NULL
    if (!head) {
        printf("список пуст\n");
    }
    //Список пуст
    if (!(*head)) {
        printf("список пуст\n");
    }
    lastbn = getLastButOne(*head);
    //Если в списке один элемент
    if (lastbn == NULL) {
        free(*head);
        *head = NULL;
    } else {
        free(lastbn->next);
        lastbn->next = NULL;
    }
}





void printLinkedList(const Node *head) {
    while (head) {
        printf("%c ", head->value);
        head = head->next;
    }
    printf("\n");
}

int Len(Node *head)  {
    int count = 0;
    Node *temp = head;
    while(temp)  {
        count++;
        temp = temp->next;
    }
return count;
}

