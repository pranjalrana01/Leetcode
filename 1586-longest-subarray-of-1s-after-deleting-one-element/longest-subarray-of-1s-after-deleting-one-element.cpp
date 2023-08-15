class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i=0,j=0,ans = 0,n = nums.size();
        int countzero = 0;
        for(;j<n;j++){
            if(nums[j] == 0)countzero++;

            for(;countzero > 1 ; i++){
                if(nums[i] == 0)countzero--;
            }
            ans = max(ans , j-i+1);
        }
        return ans-1;
    }
};