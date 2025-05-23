#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_LEN 100

struct Queue{
    int queue[MAX_LEN];
    int front;
    int rear;
};

void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

bool isEmpty(struct Queue* q){
    if(q->front == -1) return true;
    else return false;
}

void enqueue(struct Queue* q, int value){
    if(q->front == -1){
        q->front = 0;
        q->rear = 0;
        q->queue[q->front] = value;
    }
    else if((q->rear + 1) % MAX_LEN == q->front){
        printf("Queue is full.\n");
    }
    else {
        q->rear = (q->rear + 1) % MAX_LEN;
        q->queue[q->rear] = value;
    }
}

void dequeue(struct Queue* q){
    if(isEmpty(q)){
        printf("Queue has nothing to dequeue.\n");
    }
    else if(q->front == q->rear){ // 只有一個東西，拿走後就要清空queue
        initQueue(q);
    }
    else{
        q->front = (q->front + 1) % MAX_LEN;
    }
}

void printQueue(struct Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty.\n");
        return;
    }
    int i = q->front;
    while(true){
        printf("%d ", q->queue[i]);
        if(i == q->rear) break;
        i = (i + 1) % MAX_LEN;
    }
}

int main(){
    struct Queue q1;
    initQueue(&q1); // no passed by ref in C
    enqueue(&q1, 2);
    enqueue(&q1, 5);
    // enqueue(&q1, 9);
    dequeue(&q1);
    dequeue(&q1);
    // enqueue(&q1, 7);
    // enqueue(&q1, 8);
    // enqueue(&q1, 10);
    printQueue(&q1);
    return 0;
}