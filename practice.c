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
NODE dequeueAdvisor(NODE*, NODE* ,int , int);
void printChosenAdvisors(NODE);

int main() {

    int advisor, interval;
    NODE head = NULL, current = NULL, tail = NULL;
    
    while (1) {

        enqueueAdvisor(&head, &current, &tail);

        printf("Enter the starting position of the advisor : ");
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
void enqueueAdvisor(NODE* head, NODE* current, NODE* tail) {

    *head = NULL;
    *tail = NULL;

    for (int data = 0; data < ADVISORS; data++) {
        *current  = malloc(sizeof(ListDataType));
        (*current)->data = data + 1;
        (*current)->nextPointer = NULL;

        if (*head == NULL) {
            *head = *tail = *current;
        } 
        else {
            (*tail)->nextPointer = *current;
            *tail = *current;
        }
    }

    (*tail)->nextPointer = *head;
}

NODE dequeueAdvisor(NODE* current, NODE* head, int interval, int startingPosition) {
    NODE result = NULL;
    NODE previousCurrent = *current;

    // Find the starting advisor
    while (*current != NULL && (*current)->data != startingPosition) {
        previousCurrent = *current;
        *current = (*current)->nextPointer;
    }

    // Start counting and dequeue advisors
    int count = 0;
    while (count < interval) {
        // Store the dequeued advisor in the result linked list
        if (result == NULL) {
            result = malloc(sizeof(ListDataType));
            result->data = (*current)->data;
            result->nextPointer = NULL;
        } else {
            NODE temp = malloc(sizeof(ListDataType));
            temp->data = (*current)->data;
            temp->nextPointer = result;
            result = temp;
        }

        count++;

        // Check if we have reached the end of the circular linked list
        if (*current == *head) {
            break;
        }

        // Update pointers to remove the dequeued advisor
        previousCurrent->nextPointer = (*current)->nextPointer;

        // Free the dequeued advisor
        NODE temp = *current;
        *current = (*current)->nextPointer;
        free(temp);
    }

    return result;
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