// class Solution {
// public:

//     int lowerBound(vector<int>& nums, int target){
//         int start = 0;
//         int ans = -1;
//         int end = nums.size()-1;

//         while(start <= end){
//             int mid = start + (end - start)/2;

//             if(nums[mid] == target){
//                 end = mid-1;
//                 ans = mid;
//             }

//             else if(nums[mid] < target){
//                 start = mid+1;
//             }
//             else{
//                 end = mid-1;
//             }
//         }
//         return ans;
//     }


//         int upperBound(vector<int>& nums, int target){
//         int start = 0;
//         int ans2 = -1;
//         int end = nums.size()-1;

//         while(start <= end){
//             int mid = start + (end - start)/2;

//             if(nums[mid] == target){
//                 start = mid+1;
//                 ans2 = mid;
//             }

//             else if(nums[mid] < target){
//                 start = mid+1;
//             }
//             else{
//                 end = mid-1;
//             }
//         }
//         return ans2;
//     }

//     vector<int> searchRange(vector<int>& nums, int target) {
//         vector<int>output;
//         int lower = lowerBound(nums,target);
//         int upper = upperBound(nums,target);

//         output.push_back(lower);
//         output.push_back(upper);

//         return output;
//     }
// };



class Solution {
private:
    int lower_bound(vector<int>& nums, int low, int high, int target){
        while(low <= high){
            int mid = (low + high) >> 1;
            if(nums[mid] < target){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        int startingPosition = lower_bound(nums, low, high, target);
        int endingPosition = lower_bound(nums, low, high, target + 1) - 1;
        if(startingPosition < nums.size() && nums[startingPosition] == target){
            return {startingPosition, endingPosition};
        }
        return {-1, -1};
    }
};