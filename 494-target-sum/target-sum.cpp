class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int S = 0;
    for (int num : nums) {
        S += num;
    }

    // If (target + S) is odd or target is larger than the sum of all elements, return 0
    if ((target + S) % 2 != 0 || abs(target) > S) {
        return 0;
    }

    int subsetSum = (target + S) / 2;

    // Initialize a 2D dp array
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(subsetSum + 1, 0));
    
    // There's one way to get the sum 0: by choosing no elements
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }

    // Fill the dp array
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= subsetSum; ++j) {
            if (nums[i - 1] <= j) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][subsetSum];
    }
};