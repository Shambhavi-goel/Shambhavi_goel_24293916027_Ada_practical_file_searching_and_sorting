#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int value;
    int weight;
} Item;
 
int compare(const void* a, const void* b) {
    Item* itemA = (Item*)a;
    Item* itemB = (Item*)b;
    double r1 = (double)itemA->value / itemA->weight;
    double r2 = (double)itemB->value / itemB->weight;
    if (r1 < r2) return 1;
    else if (r1 > r2) return -1;
    else return 0;
}

double fractionalKnapsack(int* val, int* wt, int n, int capacity) {
    Item* items = (Item*)malloc(n * sizeof(Item));
    for (int i = 0; i < n; i++) {
        items[i].value = val[i];
        items[i].weight = wt[i];
    }

    qsort(items, n, sizeof(Item), compare);

    double max_profit = 0.0;
    int currentCapacity = capacity;

    for (int i = 0; i < n; i++) {
        if (items[i].weight <= currentCapacity) {
            max_profit += items[i].value;
            currentCapacity -= items[i].weight;
        } else {
            max_profit += ((double)items[i].value / items[i].weight) * currentCapacity;
            break;
        }
    }

    free(items);
    return max_profit;
}

int main() {
    int val[] = {30, 20, 50, 60, 80, 40, 70, 30};  //profits or values
    int wt[] = {6, 10, 3, 5, 1, 9, 7, 8}; //weights
    int capacity = 25;     //maximum capacity of knapsack
    int n = sizeof(val) / sizeof(val[0]);

    clock_t start = clock();

    // Run multiple times for stable timing
    double result = 0.0;
    for (int i = 0; i < 100000; i++) {
        result = fractionalKnapsack(val, wt, n, capacity);
    }

    clock_t end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 1000.0;

    printf("Maximum Profit = %lf\n", result);
    printf("Average Time taken for %d items: %f seconds\n", n, time_taken);

    return 0;
}
