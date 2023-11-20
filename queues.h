#define ARRAYSIZE 13
#define INTERVALS 100
#define SIZE 5

int Advisers[ARRAYSIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

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