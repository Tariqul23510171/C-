#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int minCoins(vector<int>& coins, int amount) {
    // Create a DP table to store the minimum number of coins for each amount
    vector<int> dp(amount + 1, INT_MAX);

    // Base case: The minimum number of coins to make amount 0 is 0
    dp[0] = 0;

    // Iterate through each amount from 1 to the given amount
    for (int i = 1; i <= amount; ++i) {
        // Check each coin
        for (int coin : coins) {
            if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    // If dp[amount] is still INT_MAX, it means it's not possible to make that amount
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 8;

    int result = minCoins(coins, amount);
    if (result != -1) {
        cout << "Minimum number of coins needed: " << result << endl;
    } else {
        cout << "It's not possible to make the amount with the given coins." << endl;
    }

    return 0;
}
