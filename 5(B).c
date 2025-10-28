#include <stdio.h>
#include <time.h>

int max(int a, int b) {
    return (a > b) ? a : b;
} 

// 0/1 Knapsack function using DP
int knapsack(int W, int weights[], int profits[], int n) {
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weights[i - 1] <= w)
                dp[i][w] = max(profits[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][W];
}

int main() {
    int W = 20;  //maximum capacity of knapsack
    int weights[] = {2, 3, 4, 5, 9, 7, 6, 8};    //weights of items
    int profits[] = {3, 4, 5, 8, 10, 11, 13, 15};   //profits of the items
    int n = sizeof(weights) / sizeof(weights[0]);   

    clock_t start = clock();

    // Run multiple times for stable average timing
    for (int i = 0; i < 100000; i++) {
        knapsack(W, weights, profits, n);
    }

    clock_t end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC / 1000.0;

    int maxProfit = knapsack(W, weights, profits, n);
    printf("Maximum Profit = %d\n", maxProfit);
    printf("Average Time taken for %d items: %f seconds\n", n, time_taken);

    return 0;
}
