#include <iostream>
#include <vector>
using namespace std;

// Function to solve 0/1 Knapsack using Dynamic Programming
int knapsack(int W, vector<int>& weight, vector<int>& value, int N) {
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

    // Build table dp[i][w]
    for (int i = 1; i <= N; i++) {
        for (int w = 1; w <= W; w++) {
            if (weight[i - 1] <= w) {
                dp[i][w] = max(value[i - 1] + dp[i - 1][w - weight[i - 1]],
                               dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[N][W]; // Maximum utility
}

int main() {
    int N, W;
    cout << "Enter number of items: ";
    cin >> N;

    cout << "Enter maximum truck capacity: ";
    cin >> W;

    vector<int> weight(N), value(N);
    cout << "Enter weight and utility of each item:\n";
    for (int i = 0; i < N; i++) {
        cin >> weight[i] >> value[i];
    }

    int maxUtility = knapsack(W, weight, value, N);
    cout << "\nMaximum Utility Value = " << maxUtility << endl;

    return 0;
}
