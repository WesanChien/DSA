#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next; // Node* next in C++. Or using typedef struct Node{...}Node; in C
};

struct Node* HEAD = NULL;

void insertBegin(int data){
    struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp->data = data;
    tmp->next = HEAD;
    HEAD = tmp;
}

void deleteBegin(){
    struct Node* tmp = HEAD;
    HEAD = HEAD->next;
    free(tmp);
}

void insertNth(int data, int n){
    struct Node* tmp1 = (struct Node*)malloc(sizeof(struct Node));
    tmp1->data = data;
    if(n == 1){
        tmp1->next = HEAD;
        HEAD = tmp1;
    }
    else{
        struct Node* tmp2 = HEAD;
        for(int i = 0; i < n - 2; i++){
            tmp2 = tmp2->next;
        }
        tmp1->next = tmp2->next;
        tmp2->next = tmp1;
    }
}

void deleteNth(int n){
    struct Node* tmp1 = HEAD;
    if(n == 1){
        deleteBegin();
    }
    else{
        for(int i = 0; i < n - 2; i++){
            tmp1 = tmp1->next; 
        }
        struct Node* tmp2 = tmp1->next;
        tmp1->next = tmp2->next;
        free(tmp2);
    }
}

void reverse(){
    struct Node *prv, *curr, *nxt;
    prv = NULL;
    curr = HEAD;
    while(curr != NULL){
        nxt = curr->next;
        curr->next = prv;
        prv = curr;
        curr = nxt;
    }
    HEAD = prv;
}

void printList(struct Node* n){
    while(n != NULL){
        printf("%d ", n -> data);
        n = n -> next;
    }
    printf("\n");
}