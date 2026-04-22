#include <stdio.h>

float fractionalknapsack(int n, int weight[], int profit[], int c) {
    float p = 0.0;

    // Sort by profit/weight ratio (descending)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((float)profit[j] / weight[j] < (float)profit[j + 1] / weight[j + 1]) {
                
                int temp = profit[j];
                profit[j] = profit[j + 1];
                profit[j + 1] = temp;

                temp = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = temp;
            }
        }
    }

    // Knapsack logic
    for (int i = 0; i < n; i++) {
        if (weight[i] <= c) {
            p += profit[i];
            c -= weight[i];
        } else {
            p += (float)profit[i] / weight[i] * c;
            break;
        }
    }

    return p;
}

int main() {
    int n = 4;
    int weight[] = {10, 20, 30, 40};
    int profit[] = {60, 100, 120, 140};
    int c = 50;

    float maxprofit = fractionalknapsack(n, weight, profit, c);
    printf("maximum profit = %.2f\n", maxprofit);

    return 0;
}