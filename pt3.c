/*  Group Members:          (BSCS 2-4)
        1. Llesis, Earl Gem
        2. Palpal-latoc, Alfred Joshua I.
        3. Torres, Nigel Frederick J.
        4. Montemayor, Keith Reijay
        5. Bognot, Kristina Cassandra
        6. Mancilla, Natalia Angela S. 
        7. Frilles, Roljohn
        8. Reyes, Rainer Joshua
    */

#include <stdio.h>
#include <stdlib.h> // for memory allocation (malloc)
#define ADVISORS 13 // there are 13 advisors of the president
#define NUMSELECTED 5 // only 5 can be selected from them

struct adviserNode {
    int data;
    struct adviserNode *next;
}; // structure node linked list

typedef struct adviserNode listDataType;    //name of datatype is 'listDataType'
typedef listDataType *NODEPTR;              //name of the datatype is '*NODEPTR'

NODEPTR head, tail, current;

NODEPTR enqueueAdviser(int);                //Function to make a node for each adviser
NODEPTR queueCircle(int);                   //Function to connect each node into a circular form
void dequeueSelection(NODEPTR*, int, int);  //Function to Select the Chosen Adviser in dequeue it from the queue
void freeNodes(NODEPTR*);                   //Function to free memory

int main() {
    int start, interval;

    while (1){
        printf("\nSelect a Starting Point Adviser: ");
        scanf("%d", &start);

        if (start == 0) {
            printf("\nExiting the Program...\n");
            break; // Exit the program
        }

        printf("Interval: ");
        scanf("%d", &interval);

        if (start < 1 || start > 13 || interval < 1 || interval > 100) {
            printf("Invalid input. Please enter valid values.\n");
            continue;
        }

        printf("=============================================\n");
        NODEPTR adviserCircle = queueCircle(ADVISORS);
        dequeueSelection(&adviserCircle, start, interval);
        printf("=============================================");

        freeNodes(&adviserCircle);
        
    }

    return 0;
}

/*Function to make a node for each adviser*/
NODEPTR enqueueAdviser(int num) {
    NODEPTR newAdviser = malloc(sizeof(listDataType));
    if (newAdviser != NULL) {
        newAdviser->data = num;
        newAdviser->next = NULL;
    }
    return newAdviser;
}

/*Function to connect each node into a circular form*/
NODEPTR queueCircle(int numAdvisers) {

    head = tail = NULL;

    for (int i = 1; i <= numAdvisers; i++) {
        NODEPTR newAdviser = enqueueAdviser(i);
        if (newAdviser != NULL) {
            if (head == NULL) {
                head = tail = newAdviser;
            } else {
                tail->next = newAdviser;
                tail = newAdviser;
            }
        }
    }

    if (tail != NULL) tail->next = head; // Make it circular

    return head;
}

/*Function to Select the Chosen Adviser in dequeue it from the queue*/
void dequeueSelection(NODEPTR *head, int start, int interval) {
    
    printf("Chosen Advisers: ");
    current = *head;

    for (int i = 1; i < start; i++) {
        current = current->next; // Move to the starting adviser
    }

    for (int i = 0; i < NUMSELECTED; i++) {
        for (int j = 1; j < interval; j++) {
            current = current->next;
        }   // For counting interval

        printf("%d", current->data);

        // Removes comma at the end of chosen advisors
        if (i < NUMSELECTED - 1) printf(", ");

        NODEPTR temp = current->next;
        // Remove the selected adviser from the circle
        current->data = temp->data;
        current->next = temp->next;
        
        if (temp == *head) *head = temp->next;
        
        free(temp);
    }
   
    printf("\n");
}

/*Function to delete all nodes*/
void freeNodes(NODEPTR *head) {
    current = *head;
    NODEPTR temp;

    if (*head != NULL) {
        do {
            temp = current->next;
            free(current);
            current = temp;
        } while (current != *head);
    }

    *head = NULL;
}
