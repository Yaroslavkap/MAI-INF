#include<stdio.h>
#include<stdlib.h>
#include "list.h"



int main(void)
{
    Node* head = NULL;
    
    int n = 0;
    char command;
    char gg;
    
    
    
    printf("введите:\n1) чтобы добавить элемент в конец\n2) чтобы добавить элемент в начало \n3) чтобы удалить элемент с конца \n4) чтобы удалить элемент из начала \n5) чтобы вывести список \n6) чтобы добавить k экземпляров последнего элемента в начало списка\n7) чтобы узнать длину списка\n");
    
    
    
    do
    {
        scanf("%c", &command);
    
        if(command == '1') {
            if (n != 0) {
                char v = 0;
                printf("\nзначение: ");
                scanf("%c%c", &gg, &v);
                pushBack(head, v);
            } else {
                char w = 0;
            printf("\nзначение: ");
            scanf("%c%c",&gg, &w);
            push(&head, w);
            }
            n++;
        }
        
        if(command == '5') {
            printLinkedList(head);
        }
        
        if(command == '3') {
            if (n != 0) {
                popBack(&head);
                n--;
            } else {
                printf("список пуст\n");
            }
        }
        
        if(command == '2') {
            char w = 0;
            printf("\nзначение: ");
            scanf("%c%c",&gg, &w);
            push(&head, w);
            n++;
        }
        
        if(command == '4') {
            if (n != 0) {
                pop(&head);
                n--;
            } else {
                printf("список пуст\n");
            }
        }
        
        
        
        if(command == '6') {
            if (n != 0) {
                int k;
                printf("введите k:");
                scanf("%d", &k);
                Node *last = getLast(head);
                for (int i = 0; i < k; i++) {
                   push(&head, last->value);
                }
            } else {
                printf("список пуст\n");
            }
        }
        
        if(command == '7') {
            int l;
            l = Len(head);
            printf("длина списка равна: %d\n", l);
        }
        
        
        
        
        
    }while(command != '0');
    printf("выход\n");
    
    return 0;
    

}
