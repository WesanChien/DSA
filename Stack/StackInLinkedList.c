#include<stdio.h>
#include<stdlib.h>

struct StackNode {
    int data;
    struct StackNode *next;

};

struct StackNode *TOP = NULL;

void push(int data) {
    struct StackNode *tmp = (struct StackNode*)malloc(sizeof(struct StackNode));
    tmp->data = data;
    tmp->next = TOP;
    TOP = tmp;
}

void pop() {
    struct StackNode *tmp;
    if(TOP == NULL) printf("Stack is empty\n");
    tmp = TOP;
    TOP = TOP->next;
    free(tmp);
}

void top(struct StackNode *s) {
    if (s == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("%d\n", s->data);
}

void print(struct StackNode *s) {
    if (s == NULL) {
        printf("Stack is empty\n");
        return;
    }
    while(s != NULL){
        printf("%d ", s->data);
        s = s->next;
    }
    printf("\n");
}

int main() {
    push(3); // not pass by ref in C, therefore we need to use addr.
    push(14);
    push(52);
    print(TOP); 
    pop();
    top(TOP); 
    push(48);
    print(TOP);
    return 0;
}


