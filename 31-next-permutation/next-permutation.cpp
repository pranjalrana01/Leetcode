class Solution {
public:
    void solve(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // Find the first decreasing element from the end
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            int j = n - 1;
            // Find the element just larger than nums[i]
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            // Swap them
            swap(nums[i], nums[j]);
        }

        // Reverse the elements after the position i
        reverse(nums.begin() + i + 1, nums.end());
    }

    void nextPermutation(vector<int>& nums) {
        solve(nums);
    }
};
