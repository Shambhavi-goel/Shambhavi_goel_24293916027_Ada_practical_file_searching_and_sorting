#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int start;
    int finish;
    int index; 
} Activity;

int compare(const void *a, const void *b) {
    Activity *actA = (Activity *)a;
    Activity *actB = (Activity *)b;
     if (actA->finish < actB->finish)
        return -1;   // actA should come before actB
    else if (actA->finish > actB->finish)
        return 1;    // actA should come after actB
    else
        return 0;    // both are equal
}

void activitySelection(int arr2D[][2], int n) {
    Activity *arr = (Activity *)malloc(n * sizeof(Activity));
    if (!arr) {
        printf("Memory allocation failed\n");
        return;
    }

    for (int i = 0; i < n; i++) {
        arr[i].start = arr2D[i][0];
        arr[i].finish = arr2D[i][1];
        arr[i].index = i + 1; 
    }

    qsort(arr, n, sizeof(Activity), compare);

    printf("Selected activities:\n");
    printf("Activity\tStart\tFinish\n");

    int count = 1;  
    int j = 0;

    printf("A%d\t\t%d\t%d\n", arr[j].index, arr[j].start, arr[j].finish);

    for (int i = 1; i < n; i++) {
        if (arr[i].start >= arr[j].finish) {
            count++;
            printf("A%d\t\t%d\t%d\n", arr[i].index, arr[i].start, arr[i].finish);
            j = i;
        }
    }

    printf("\nTotal number of selected activities: %d\n", count);

    free(arr);
}

int main() {
    int activities[][2] = { {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9},
    {5, 9}, {7, 8}, {9, 10}, {11, 12}, {12, 13}};
    int n = sizeof(activities) / sizeof(activities[0]);

    clock_t start = clock();
    activitySelection(activities, n);
    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken for Activity Selection: %f seconds\n", time_taken);

    return 0;
}
