#include <stdio.h>
#include <stdlib.h>

//Define the structure for a node in a singly linked list
struct ListNode
{
    int data;               //Hold an integer value
    struct ListNode *next;  //Points to the next node
};  

typedef struct ListNode listDataType;   //name of datatype is 'listDataType'
typedef listDataType *NODE;             //name of the datatype is '*NODE'

void pushNode(NODE*, int);              //Function to add a node at the beginning of a linked list
NODE convertToInt(const char*);         //Function to convert string into int linked list
NODE additionLinkedList(NODE, NODE);    //Function to add the two linked lists
void printSummation(NODE);              //Function to print the summation of the two linked lists
void freeLinkedList(NODE);              //Function to free all nodes

int main() {
    char value[100];            //define the string size

    printf("First Addend:   ");    //input for first addend linked list
    scanf("%s", value);
    NODE firstAddend = convertToInt(value);     //assigned the conversion of the value to FirstAddend

    printf("Second Addend:   ");    //input for first addend linked list
    scanf("%s", value);
    NODE secondAddend = convertToInt(value);    //assigned the conversion of the value to FirstAddend

    NODE result = additionLinkedList(firstAddend, secondAddend);    //assigned the summation of the two linked lists to variable 'result'

    printSummation(result);     //print the summation of the two linked lists

    /*free all the memory of the linked lists*/
    freeLinkedList(firstAddend);
    freeLinkedList(secondAddend);
    freeLinkedList(result);

    return 0;
}

/*Function to add a node at the beginning of a linked list*/
void pushNode (NODE* head, int digitData) {
    NODE newNode = malloc(sizeof(listDataType));    // Create a new node
    newNode->data = digitData;
    newNode->next = *head;
    *head = newNode;
}

/*Function to convert string into int linked list*/
NODE convertToInt(const char* string) {
    
    NODE result = NULL;     //local variable of NODE result
    
    for (int i = 0; string[i] != '\0'; i++) {   // Traverse the string from right to left and convert each character to an integer
        pushNode(&result, string[i] - '0'); 
    }

    return result;
}

/*Function to add the two linked lists*/
NODE additionLinkedList(NODE firstAddend, NODE secondAddend) {
    
    NODE result = NULL;     //local variable of NODE result
    NODE current = NULL;    //local variable of NODE current
    int carry = 0;

    /*Iterate through the linked lists, adding the corresponding digits and handling carry*/
    while (firstAddend != NULL || secondAddend != NULL) {
        int addend1 = (firstAddend != NULL) ? firstAddend->data : 0;    //addend1 holds firstAddend->data value; otherwise, the value is zero  
        int addend2 = (secondAddend != NULL) ? secondAddend->data : 0;  //addend2 holds secondAddend->data value; otherwise, the value is zero

        int sum = addend1 + addend2 + carry;
        carry = sum / 10;               //holds the carry for the next addition step
        pushNode(&result, sum % 10);    //push the remainder to the summation of linked list

        if (firstAddend != NULL) firstAddend = firstAddend->next;       //access the next node
        if (secondAddend != NULL) secondAddend = secondAddend->next;    //access the next node
    }

    if(carry > 0) pushNode(&result, carry);     //if there is still a carry, push the remainder to the summation of linked list

    return result;
}

/*Function to print the summation of the two linked lists*/
void printSummation(NODE head) {

    printf("TOTAL: ");
    
    while(head != NULL) {   //loop will continue until all nodes are exhausted
        printf("%d", head->data);
        head = head->next;
        if(head != NULL) printf(" <- ");
    }
}

/*Function to free all nodes*/
void freeLinkedList(NODE head){
    
    NODE temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}