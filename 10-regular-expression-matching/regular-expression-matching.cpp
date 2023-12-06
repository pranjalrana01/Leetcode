class Solution {
public:
    bool isMatch(string s, string p) {
int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true; // empty string matches empty pattern
        
        // Handle patterns with '*' at the beginning
        for (int j = 1; j <= n; j++) {
            if (p[j-1] == '*') {
                dp[0][j] = dp[0][j-2];
            }
        }
        
        // Fill in the rest of the DP table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i-1] == p[j-1] || p[j-1] == '.') {
                    dp[i][j] = dp[i-1][j-1];
                } else if (p[j-1] == '*') {
                    if (s[i-1] == p[j-2] || p[j-2] == '.') {
                        dp[i][j] = dp[i][j-2] || dp[i-1][j];
                    } else {
                        dp[i][j] = dp[i][j-2];
                    }
                }
            }
        }
        
        return dp[m][n];
    }
};