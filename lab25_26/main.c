#include "deque.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter the deque size\n");
    int n;
    int a;
    int action;
    deque d;
    deque_create(&d);
    deque d2;
    deque_create(&d2);
    
    
    
    do
	{
		printf("Меню\n");
		printf("Первый дек (второй дек)\n ");
		printf("11 (21)) Добавить элемент слева\n");
		printf("12 (22)) Добавить элемент справа\n");
		printf("13 (23)) Удалить элемент слева\n");
		printf("14 (24) Удалить элемент справа\n");
		printf("15 (25)) Размер дека\n");
		printf("16 (26)) Сортировка\n");
		printf("17 (27)) Печать\n");
		printf("99) Объединение деков\n");
		printf("0) Выход\n");
		printf("Выберите действие: ");
		scanf("%d", &action);

		switch (action)
		{
			case 11:
			{
				printf("Введите ключ: ");
				scanf("%d", &a);
				push_front(&d, a);
				

				break;
			}

			case 12:
			{
				printf("Введите ключ: ");
				scanf("%d", &a);
				push_back(&d, a);
				break;
			}

			case 13:
			{
				if (deque_size(&d) > 0)
				{
					pop_front(&d);
				}
				else
					printf("Дек пуст\n");

				break;
			}

			case 14:
			{
				if (deque_size(&d) > 0)
				{
					pop_back(&d);
				}
				else
					printf("Дек пуст\n");

				break;
			}

			case 15:
			{
				printf("Размер дека(1): %d \n", deque_size(&d));

				break;
			}

			case 16:
			{
				qs(&d, 0, deque_size(&d) - 1);

				break;
			}
			
			case 17:
			{
				print(&d);

				break;
			}
			case 19:
			{
				rev(&d);

				break;
			}

			
			
			
			case 21:
			{
				printf("Введите ключ: ");
				scanf("%d", &a);
				push_front(&d2, a);
				

				break;
			}

			case 22:
			{
				printf("Введите ключ: ");
				scanf("%d", &a);
				push_back(&d2, a);
				break;
			}

			case 23:
			{
				if (deque_size(&d2) > 0)
				{
					pop_front(&d2);
				}
				else
					printf("Дек пуст\n");

				break;
			}

			case 24:
			{
				if (deque_size(&d2) > 0)
				{
					pop_back(&d2);
				}
				else
					printf("Дек пуст\n");

				break;
			}

			case 25:
			{
				printf("Размер дека(2): %d \n", deque_size(&d2));

				break;
			}

			case 26:
			{
				qs(&d2, 0, deque_size(&d2) - 1);

				break;
			}
			
			case 27:
			{
				print(&d2);

				break;
			}
			case 29:
			{
				rev(&d2);

				break;
			}
			
			case 99:
			{
				conc(&d, &d2);

				break;
			}

			
			

			case 0: break;

			default:
			{
				printf("Ошибка. Такого пункта меню не существует\n");

				break;
			}
		}
	}
	while (action != 0);
	

	return 0;
}
