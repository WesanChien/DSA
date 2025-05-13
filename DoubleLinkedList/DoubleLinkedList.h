#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next; // Node* next in C++. Or using typedef struct Node{...}Node; in C
    struct Node *prev;
};

struct Node *HEAD = NULL;

struct Node *newNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertBegin(int data)
{
    struct Node *tmp = newNode(data);
    if (HEAD == NULL)
    {
        HEAD = tmp;
    }
    else
    {
        tmp->next = HEAD;
        HEAD->prev = tmp;
        HEAD = tmp;
    }
}

void deleteBegin()
{
    struct Node *tmp = HEAD;
    HEAD = HEAD->next;
    free(tmp);
}

void insertNth(int data, int n)
{
    struct Node *tmp = newNode(data);
    struct Node *curr = HEAD;
    if (HEAD == NULL)
    {
        insertBegin(data);
    }
    else if (n == 1)
    {
        insertBegin(data);
    }
    else
    {
        for (int i = 0; i < n - 2; i++)
        {
            curr = curr->next;
        }
        struct Node *nxt = curr->next;
        tmp->next = nxt;
        tmp->prev = curr;
        if (nxt != NULL)
        {
            nxt->prev = tmp;
        }
        curr->next = tmp;
    }
}

void deleteNth(int n)
{
    struct Node *curr = HEAD;
    if (HEAD == NULL)
    {
        return;
    }
    else if (n == 1)
    {
        deleteBegin();
        return;
    }
    else
    {
        for (int i = 0; i < n - 1; i++)
        {
            curr = curr->next;
        }
        struct Node *nxt = curr->next;
        struct Node *prv = curr->prev;
        if (prv != NULL)
        {
            prv->next = nxt;
        }
        if (nxt != NULL)
        {
            nxt->prev = prv;
        }
        free(curr);
    }
}

void reverse()
{
    struct Node *curr, *nxt, *prv;
    prv = NULL;
    curr = HEAD;
    while(curr != NULL){
        nxt = curr->next;
        curr->next = prv;
        curr->prev = nxt;
        prv = curr;
        curr = nxt;
    }
    HEAD = prv;
}

void printList(struct Node *n)
{
    while (n != NULL)
    {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}
