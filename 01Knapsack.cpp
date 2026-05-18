#include <iostream>
using namespace std;

int knapsack(int W, int weights[], int profits[], int n) {
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = (dp[i - 1][w]>(dp[i - 1][w - weights[i - 1]] + profits[i - 1]))?
                            dp[i - 1][w]:(dp[i - 1][w - weights[i - 1]] + profits[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}
int main() {
    int weights[] = {1, 3, 4, 5};
    int profits[] = {1, 4, 5, 7};
    int W = 7;
    int n = 4;

    int maxProfit = knapsack(W, weights, profits, n);
    cout<<"Maximum profit: "<<maxProfit<<endl;

    return 0;
}
