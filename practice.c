#include <stdio.h>
#include <stdlib.h>
#define ADVISORS 13

struct listNode {
    int data;
    struct listNode *nextPointer;
};

typedef struct listNode ListDataType;
typedef ListDataType *NODE;

void enqueueAdvisor(NODE*, NODE*, NODE*);
NODE dequeueAdvisor(NODE*, NODE* , int, int);
void printChosenAdvisors(NODE);

int main() {

    int advisor, interval;
    NODE head = NULL, current = NULL, tail = NULL;

    while (1) {

        enqueueAdvisor(&head, &current, &tail);

        printf("Start        : ");
        scanf("%d", &advisor);
        
        if(advisor == 0) {
            printf("Exiting the Program...");
            break;
        }

        printf("Interval    : ");
        scanf("%d", &interval);

        NODE result = dequeueAdvisor(&current, &head, interval, advisor);

        printChosenAdvisors(result);
    }
    
    return 0;
}

/*Function to create the queue of adviser 1 to 13*/
void enqueueAdviser(NODE* head, NODE* current, NODE* tail) {

    for (int data = 0; data < ADVISORS; data++) {
        
        *current  = malloc(sizeof(ListDataType));
        (*current)->data = data + 1;
        (*current)->nextPointer = NULL;

        if (head == NULL) {
            *head = *tail = *current;
        } 
        else {
            (*tail)->nextPointer = *current;
            *tail = *current;
        }
    }

    (*tail)->nextPointer = *head;
}

NODE dequeueAdviser(NODE* current, NODE* head, int interval, int startingPosition) {

    int num = 0;
    NODE *result = NULL;
    NODE previousCurrent = *current;

    while (num < ADVISORS) {
       
        if ((*current)->data == startingPosition) {
            result = malloc(sizeof(ListDataType));
            (*result)->data = (*current)->data;
            (*result)->nextPointer = NULL;
            num++;
        }
        else {
            previousCurrent->nextPointer = (*current)->nextPointer;
            free(*current);
            (*current)->nextPointer = previousCurrent->nextPointer;
        }
        previousCurrent = *current;
        *current = (*current)->nextPointer;
    }

    return *result;
}

void printChosenAdvisors(NODE result) {

    printf("Chosen Advisers : ");
    while(result != NULL) {   //loop will continue until all nodes are exhausted
        printf("%d", result->data);            
        result = result->nextPointer;
        if(result != NULL) printf(", ");
    }
    printf("\n");
}