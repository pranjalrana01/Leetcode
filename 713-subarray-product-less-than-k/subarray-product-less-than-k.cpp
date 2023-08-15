class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long i=0, j=0, n=nums.size(), ans = 0;
        int product = 1;
        for(;j<n ; j++){
            product = product*nums[j];

            for(;product>= k && i<=j ; i++){
                product = product / nums[i];
            }
            ans += (j-i+1);
        }
        return ans;
    }
};