class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0;
        int sum = 0;
        int minlen = INT_MAX;

        for (int end = 0; end < nums.size(); end++) {
            sum += nums[end];

            while (sum >= target) {
                minlen = min(minlen, end - start + 1);
                sum -= nums[start];
                start++;
            }
        }

        return (minlen == INT_MAX) ? 0 : minlen;
    }
};
