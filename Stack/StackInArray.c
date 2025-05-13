#include<stdio.h>
#define MAX_SIZE 100

struct Stack {
    int stack[MAX_SIZE];
    int top;

};

void push(struct Stack *s, int value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->stack[++(s->top)] = value;
}

void pop(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return;
    }
    s->top--;
}

void top(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("%d\n", s->stack[s->top]);
}

void isEmpty(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Stack is not empty\n");
    }
}

void print(struct Stack *s) {
    if (s->top == -1) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->stack[i]);
    }
    printf("\n");
}

int main() {
    struct Stack s;
    s.top = -1;
    push(&s, 3); // not pass by ref in C, therefore we need to use addr.
    push(&s, 14);
    push(&s, 52);
    print(&s); 
    pop(&s);
    top(&s); 
    push(&s, 48);
    print(&s);
    return 0;
}


