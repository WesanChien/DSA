#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node* next;
};

struct QueueLinkedList{
    struct Node* HEAD;
    struct Node* REAR;
};

void enqueue(struct QueueLinkedList* q, int x){
    struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
    tmp->data = x;
    tmp->next = NULL;
    if(q->HEAD == NULL){
        q->HEAD = tmp;
        q->REAR = tmp;
        return;
    }
    q->REAR->next = tmp;
    q->REAR = tmp;
}

void dequeue(struct QueueLinkedList* q){
    struct Node* tmp = q->HEAD;
    if(q->HEAD == NULL){
        printf("Nothing in Queue.");
        return;
    }
    else if(q->HEAD == q->REAR){
        q->HEAD = q->REAR = NULL;
    }
    else{
        q->HEAD = q->HEAD->next;
    }
    free(tmp);
}

void printQueue(const struct QueueLinkedList* q){
    struct Node* tmp = q->HEAD;
    while(tmp != NULL){
        printf("%d ", tmp->data);
        tmp = tmp->next;
    }
}

int main(){
    struct QueueLinkedList q1 = {NULL, NULL};
    enqueue(&q1, 2);
    enqueue(&q1, 9);
    enqueue(&q1, 3);
    enqueue(&q1, 7);
    dequeue(&q1);
    dequeue(&q1);
    enqueue(&q1, 8);
    printQueue(&q1);
    struct QueueLinkedList* q2 = (struct QueueLinkedList*)malloc(sizeof(struct QueueLinkedList));
    q2->HEAD = q2->REAR = NULL;
    enqueue(q2, 65);
    enqueue(q2, 92);
    enqueue(q2, 34);
    enqueue(q2, 67);
    dequeue(q2);
    dequeue(q2);
    enqueue(q2, 33);
    printQueue(q2);
    return 0;
}