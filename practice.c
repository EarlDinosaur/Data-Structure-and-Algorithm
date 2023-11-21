#include <stdio.h>
#include <stdlib.h>
#define ADVISERS 13

struct listNode {
    int data;
    struct listNode *nextPointer;
};

typedef struct listNode ListDataType;
typedef ListDataType *NODE;

void enqueueAdviser(NODE*, NODE*, NODE*);
NODE startingPoint(NODE* , int);
void dequeueAdviser(NODE , int, int);

int main() {

    int adviser, interval;
    NODE head = NULL, current = NULL, tail = NULL;

    while (adviser > 0) {

        enqueueAdviser(&head, &current, &tail);

        printf("Start        : ");
        scanf("%d", &adviser);

        int startingPosition = startingPoint(&head, adviser);
        
        printf("Interval    : ");
        scanf("%d", &interval);

        dequeueAdviser(current, interval, startingPosition);
    }
    
    return 0;
}

/*Function to create the queue of adviser 1 to 13*/
void enqueueAdviser(NODE* head, NODE* current, NODE* tail) {

    for (int data = 0; data < ADVISERS; data++) {
        
        *current  = malloc(sizeof(ListDataType));
        (*current)->data = data + 1;
        (*current)->nextPointer = NULL;

        if (head == NULL) {
            *head = *tail = *current;
        } 
        else {
            (*tail)->nextPointer = current;
            *tail = current;
        }
    }

    (*tail)->nextPointer = head;
}

/*Function to find the initial point for each interval*/
NODE startingPoint(NODE *head, int start) {

    NODE current = *head;

    while (current->data != start) {
        NODE temp = current;
        current = current->nextPointer;
        free(temp);
    }

    return current;
}

void dequeueAdviser(NODE current, int interval, int startingPosition) {

    int num = 0;
    NODE result = NULL;

    while (num < ADVISERS) {
        
        if (current->data == startingPosition)
        {
            result = malloc(sizeof(ListDataType));
            result->data = current;
            result->nextPointer = NULL;
        }
        else {
            result = result->nextPointer;
        }   
    }
}