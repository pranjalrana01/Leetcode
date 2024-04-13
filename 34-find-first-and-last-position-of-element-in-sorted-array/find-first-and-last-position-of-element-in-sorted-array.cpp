class Solution {
public:

    int lowerBound(vector<int>& nums, int target){
        int start = 0;
        int ans = -1;
        int end = nums.size()-1;

        while(start <= end){
            int mid = start + (end - start)/2;

            if(nums[mid] == target){
                end = mid-1;
                ans = mid;
            }

            else if(nums[mid] < target){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return ans;
    }


        int upperBound(vector<int>& nums, int target){
        int start = 0;
        int ans2 = -1;
        int end = nums.size()-1;

        while(start <= end){
            int mid = start + (end - start)/2;

            if(nums[mid] == target){
                start = mid+1;
                ans2 = mid;
            }

            else if(nums[mid] < target){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return ans2;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>output;
        int lower = lowerBound(nums,target);
        int upper = upperBound(nums,target);

        output.push_back(lower);
        output.push_back(upper);

        return output;
    }
};