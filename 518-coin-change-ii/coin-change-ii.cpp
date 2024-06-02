class Solution {
public:
    int change(int sum, vector<int>& coins) {
        if (sum == 0) return 1; // If the target sum is 0, there's one way (using no coins).
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

        // Initialize dp array
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1; // There is one way to make sum 0 (by not using any coins)
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= sum; ++j) {
                if (coins[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][sum];
    }
};
