class Solution {
public:
    int numDecodings(std::string s) {
        if (s.empty() || s[0] == '0') return 0;
    
    int a = 1, b = 1;  // a: dp[i-2], b: dp[i-1]
    
    for (size_t i = 1; i < s.size(); ++i) {
        int temp = b;
        if (s[i] == '0') {
            if (s[i - 1] > '2' || s[i - 1] == '0') return 0;
            b = a;
        } else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7')) {
            b = b + a;
        }
        a = temp;
    }
    
    return b;

    }
};