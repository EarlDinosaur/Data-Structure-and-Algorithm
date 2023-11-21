#include <stdio.h>
#include <stdlib.h>
#include "queues.h"
#define SIZE 5

int main() {

    int start, interval, *result;
    while(start > 0) {
        
        printf("Start       : ");
        scanf("%d", &start);


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

int selectionAdviser(int chosen, int interval) {

    int result[SIZE], num = 0;

    while (num < SIZE) {
        
        if (result[num] == Advisers[chosen]) {
            chosen++;
        }
        else {
            result[num] = Advisers[chosen];
        }
        
        chosen += chosen;

        if (chosen > 13) chosen - 13;

        num++;
    }
    return *result;
}

void printChosenAdviser(int* result) {

    printf("Chosen Advisers     : ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d", result[i]);
        if (i < SIZE - 1) printf(", ");
    }
}