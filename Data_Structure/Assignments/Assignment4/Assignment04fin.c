#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

int n = 0;
typedef struct node {
    struct node* next;
    int data;
}node;

typedef struct Queue {
    node* front;
    node* rear;
}Queue;

node* getnode() {
    struct node* p = (node*)malloc(sizeof(node));
    return p;
}

void emptyqueueexception() {
    printf("Empty Stack Exception!!");
}
void putnode(node* p) {
    free(p);
    return;
}

int is_empty(node* p) {
    return p == NULL;
}
//


void enqueue(Queue* queue, int e) {
    n++;
    node* p = getnode();
    p->data = e;
    p->next = NULL;

    if (is_empty(queue->front)) {
        queue->front = p;
        queue->rear = p;
    }
    else {
        queue->rear->next = p;
        queue->rear = p;
    }
}
int dequeue(Queue* queue1) {
    n--;
    if (is_empty(queue1->front)) {
        emptyqueueexception();
    }
    int e = queue1->front->data;
    node* p = queue1->front;
    queue1->front = queue1->front->next;
    if (queue1->front == NULL)
        queue1->rear = NULL;
    return e;
}
int front(Queue*queue1) {
    if (is_empty(queue1->front))
        emptyqueueexception();
    return queue1->front->data;
}
void is_emptystack(Queue * queue) {
    if (is_empty(queue->front)) {
        printf("Empty");
        return;
    }
    printf("Nonempty");
    return;
}
int top(Queue* queue1, Queue*queue2) {
    if (is_empty(queue1->front)) {
        emptyqueueexception();
        return NULL;
    }
    while (is_empty(queue1->front->next)!=1) {
        enqueue(queue2, dequeue(queue1));
    }
    int e = queue1->front->data;
    enqueue(queue2, dequeue(queue1));
    while (is_empty(queue2->front)!=1) {
        enqueue(queue1, dequeue(queue2));
    }
    return e;
}
void push(Queue* queue, int e) {
    enqueue(queue, e);
}
void pushmillion(Queue* queue1) {
    int e;
    for (int i = 0; i < 1000000; i++) {
        e = rand() % 90 + 10;
        push(queue1, e);
    }
}



int pop(Queue * queue1, Queue * queue2) {
    if (is_empty(queue1->front)) {
        emptyqueueexception();
        return NULL;
    }
    while (is_empty(queue1->front->next)!=1) {
        enqueue(queue2, dequeue(queue1));
    }
    int e = queue1->front->data;
    dequeue(queue1);
    while (is_empty(queue2->front)!=1) {
        enqueue(queue1, dequeue(queue2));
    }
    return e;
}

void initQueue(Queue* queue)
{
    queue->front = NULL;
    queue->rear = NULL;

}

int main() {
    srand(time(NULL));
    LARGE_INTEGER ticksPerSec;
    LARGE_INTEGER start, end, diff;
    QueryPerformanceFrequency(&ticksPerSec);
    double sec;

    Queue queue1;
    initQueue(&queue1);
    Queue queue2;
    initQueue(&queue2);


    char cmd = 'a';
    int e;
    while (cmd != 'q') {
        scanf("%c", &cmd);
        if (cmd == 'S') {
            getchar();
            QueryPerformanceCounter(&start);
            is_emptystack(&queue1);
            QueryPerformanceCounter(&end);
            diff.QuadPart = end.QuadPart - start.QuadPart;
            sec = (double)diff.QuadPart / (double)ticksPerSec.QuadPart;
            printf(" (%d), cputime = %013.10f\n", n, sec * 1000);
        }
        else if (cmd == 't') {
            getchar();
            QueryPerformanceCounter(&start);
            e = top(&queue1,&queue2);
            QueryPerformanceCounter(&end);
            diff.QuadPart = end.QuadPart - start.QuadPart;
            sec = (double)diff.QuadPart / (double)ticksPerSec.QuadPart;
            if (e != NULL)
                printf("%d (%d), cputime = %013.10f\n", e, n, sec * 1000);
            else
                printf(" (%d), cputime = %013.10f\n", n, sec * 1000);

        }
        else if (cmd == 'p') {
            QueryPerformanceCounter(&start);
            char c;
            while (scanf("%d%c", &e, &c) == 2) {
                push(&queue1, e);
                if (c == '\n') {
                    break;
                }
            }
            QueryPerformanceCounter(&end);
            diff.QuadPart = end.QuadPart - start.QuadPart;
            sec = (double)diff.QuadPart / (double)ticksPerSec.QuadPart;
            printf("OK (%d), cputime = %013.10f\n", n, sec * 1000);

        }
        else if (cmd == 'P') {
            getchar();
            QueryPerformanceCounter(&start);
            pushmillion(&queue1);
            QueryPerformanceCounter(&end);
            diff.QuadPart = end.QuadPart - start.QuadPart;
            sec = (double)diff.QuadPart / (double)ticksPerSec.QuadPart;
            printf("OK (%d), cputime = %013.10f\n", n, sec * 1000);

        }
        else if (cmd == 'o') {
            getchar();
            QueryPerformanceCounter(&start);
            e = pop(&queue1,&queue2);
            QueryPerformanceCounter(&end);
            diff.QuadPart = end.QuadPart - start.QuadPart;
            sec = (double)diff.QuadPart / (double)ticksPerSec.QuadPart;
            if (e != NULL)
                printf("%d (%d), cputime = %013.10f\n", e, n, sec * 1000);
            else
                printf(" (%d), cputime = %013.10f\n", n, sec * 1000);
        }

    }
}