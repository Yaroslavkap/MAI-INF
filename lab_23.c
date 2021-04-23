#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tree {
    int data;
    struct Tree *left;
    struct Tree *right;
    struct Tree *parent;
} Tree;


Tree *root_create(int value) 
{
    Tree *tree = (Tree*)malloc(sizeof(Tree));
    tree->data = value;
    tree->left = NULL;
    tree->right = NULL;
    tree->parent = NULL;
    return tree;
}

Tree *tree_add_element(Tree *root, int value)
{ 
    if (root == NULL) {
        
        return root_create(value);
    }

    Tree *NewTree = (Tree*)malloc(sizeof(Tree));
    NewTree->data = value;
    Tree *tree1 = root;
    Tree *tree2 = NULL;

    while (tree1 != NULL) {
        tree2 = tree1;
        if (value < tree1->data) {
            tree1 = tree1->left;
        }
        else if (value > tree1->data) {
            tree1 = tree1->right;
        }
        else {
            printf("Данный элемент уже существует\n");
            return root;
        }
    }
    NewTree->parent = tree2;
    NewTree->left = NULL;
    NewTree->right = NULL;
    if (value < tree2->data) {
        tree2->left = NewTree;
    } else {
        tree2->right = NewTree;
    }
    
    return root;
}

void tree_print(Tree *root, int n) 
{
    if (root != NULL) {
        tree_print(root->right, n + 1);
        for (int i = 0; i < n; i++) printf("\t");
        printf("%d\n", root->data);
        tree_print(root->left, n + 1);
    }
}


Tree *search_in_tree(Tree *root, int value)
{
    if (root == NULL) {
        return NULL;
    }
    if (root->data == value) {
        return root;
    }
    if (value > root->data) {
        return search_in_tree(root->right,value);
    } else {
        return search_in_tree(root->left, value);
    }
}

Tree *minimum(Tree *t) 
{
    if (t->left == NULL) {
        return t;
    }
    return minimum(t->left);
}

Tree *maximum(Tree *t) {
    if (t->right == NULL) {
        return t;
    }
    return maximum(t->right);
}

Tree *found_next_tree(Tree *yet) {
    Tree *last = yet->right;
    while (last->left != NULL) {
        last = last->left;
    }
    return last;
}

Tree *destroy(Tree *list, int data) {
    Tree *parent = NULL;
    Tree *child = list;
    while (child->data != data) {
        parent = child;
        if (child->data < data) {
            child = child->right;
        } else if (child->data > data) {
            child = child->left;
        }
    }
    //1
    if (list->left == NULL && list->right == NULL) {
        
        list = NULL;
        free(list);
    //2
    } else if (child->left == NULL && child->right == NULL) {
        if (parent->left == child) {
           
            parent->left = NULL;
            free(parent->left);
        } else {
           
            parent->right = NULL;
            free(parent->right);
        }
    //3
    } else if (child->left == NULL && child->right != NULL) {
        if (list->data == data) {
            
            list = list->right;
            free(child);
        } else if (parent->left == child) {
           
            parent->left = child->right;
            free(child);
        } else {
            
            parent->right = child->right;
            free(child);
        }
    } else if (child->right == NULL && child->left != NULL) {
        if (list->data == data) {
            list = list->left;
            
            free(child);
        } else if (parent->left == child) {
            
            parent->left = child->left;
            free(child);
        } else {
            
            parent->right = child->left;
            free(child);
        }
    //4
    } else if (child->left != NULL && child->right != NULL) {
        if (list->data == data) {
            Tree *next = found_next_tree(list);
            int rose = next->data;
            
            destroy(list,next->data);
            list->data = rose;
        } else {
            Tree *next = found_next_tree(child);
            int rose = next->data;
            
            destroy(list,next->data);
            child->data = rose;
        }
    }

    return list; 
}




int maxDepth(Tree *temp)
{
  if(temp == NULL)
  return 0;

 else
{
 int lchild = maxDepth(temp->left);
 int rchild = maxDepth(temp->right);

 if(lchild <= rchild)
 return rchild+1;

 else
  return lchild+1;

 }
 }





int main(void) 
{
        printf("\nВведите:\n");
	printf("a) чтобы добавить элемент\n");
	printf("p) чтобы вывести дерево\n");
	printf("d) чтобы удалить элемент\n");
	printf("h) чтобы узнать глубину дерева\n");
	printf("e) чтобы выйти\n");
        int n = 0;
	Tree *t = NULL;
	int value;
	char c;
	int h = 0;
	
	
	while ((c = getchar()) != EOF) {
		value = 0;
		if (c == '\n') continue;
		switch (c) {
		case 'a':
			printf("\nзначение:");
			scanf("%d", &value);
			t = tree_add_element(t, value);
			n++;
			break;
		case 'p':
			tree_print(t, 1);
			break;
		case 'd':
		        if(n != 0){
			    printf("\nзначение: ");
			    scanf("%d", &value);
			    t = destroy(t, value);
			    n--;
			} else {
			    printf("дерево пусто\n");
			}
			
			break;
		case 'h':
			h = maxDepth(t);
			printf("глубина равна %d\n", h);
			break;
		
		case 'e':
			printf("выход\n");
			return 0;
		default:
			printf("данной команды не существует\n");
			break;
		}
		
	}
}
