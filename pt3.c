/*  Group Members:          (BSCS 2-4)
        1. Llesis, Earl Gem
        2. Palpal-Latoc, Alfred Joshua I.
        3. Torres, Nigel Frederick J.
        4. Montemayor, Keith Reijay
        5. Bognot, Kristina Cassandra
        6. Mancilla, Natalia Angela S.
        7. Frilles, Roljohn
        8. Reyes, Rainer Joshua
*/

#include <stdio.h>
// for memory allocation (malloc)
#include <stdlib.h> 
// There are 13 advisors of the president
#define ADVISORS 13 
// Only five can be selected from them
#define NUMSELECTED 5 

struct adviserNode {
    int data;
    struct adviserNode *next;
}; // structure node linked list

typedef struct adviserNode listDataType;    // Initialize a Data type that is named 'listDataType'
typedef listDataType *NODEPTR;              // Initialize a pointer to the Data type 'listDataType', which is named '*NODEPTR'

NODEPTR head, tail, current;                // Initialize 3 pointers for the linked list

NODEPTR enqueueAdviser(int);                // Function to enqueue or make a node for each adviser
NODEPTR queueCircle(int);                   // Function to connect each node into a circular linked list
void dequeueSelection(NODEPTR*, int, int);  // Function to dequeue the Chosen Advisors from the queue
void freeNodes(NODEPTR*);                   // Function to free memory

int main() {
    int start, interval;
    // Create a loop for the user interface that will only end if they enter 0 as the starting point advisor
    while (1){
        printf("Select a Starting Point Adviser: "); 
        scanf("%d", &start);

        if (start == 0) {
            printf("\nExiting the Program...\n");
            break; // Exit the program
        }

        printf("Interval: ");
        scanf("%d", &interval);

        if (start < 1 || start > 13 || interval < 1 || interval > 100) {
            printf("Invalid input. Please enter valid values.");
            continue;
        }

        printf("=============================================\n");
        NODEPTR adviserCircle = queueCircle(ADVISORS);
        dequeueSelection(&adviserCircle, start, interval);
        printf("=============================================\n");

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

/*Function to connect each node into a circular linked list*/
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

/*Function to dequeue the Chosen Advisers from the queue*/
void dequeueSelection(NODEPTR *head, int start, int interval) {
    
    printf("Chosen Advisers: ");
    current = *head;

    // Move the list to the starting adviser
    for (int i = 1; i < start; i++) {
        current = current->next; 
    }

    // For transversing the list according to the interval
    for (int i = 0; i < NUMSELECTED; i++) {
        for (int j = 1; j < interval; j++) {
            current = current->next;
        }   
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

/*Function to reset or delete all nodes*/
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
