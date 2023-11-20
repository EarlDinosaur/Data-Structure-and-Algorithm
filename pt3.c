#include <stdio.h>
#include <stdlib.h>
#include "queues.h"
#define SIZE 5
int main() {

    int start, interval, *result;
    while(start > 0) {
        
        printf("Start       : ");
        scanf("%d", &start);

        /*can use the ternary operator but unable to function in my code*/
        if (start >= 0 && start <= 13) {
            if (start == 0) {
                exit(EXIT_FAILURE);
            }
            else {
                printf("Interval    : ");
                scanf("%d", &interval);
                *result = selectionAdviser(start, interval);
            }
        }
        else {
            printf("Please try again...");
        }

        printChosenAdviser(result);
    }

    return 0;
}