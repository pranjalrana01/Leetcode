class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int, int>mpp;
        for(int i=0; i<nums.size(); i++){
            int need = target - nums[i];
            if(mpp.find(need) !=0){
                ans.push_back(i);
                ans.push_back(mpp[need]);
                break;
            }
            mpp[nums[i]] = i;
        }
        return ans;
    }
};