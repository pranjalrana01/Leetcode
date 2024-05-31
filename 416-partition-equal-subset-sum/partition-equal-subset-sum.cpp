class Solution {
public:
    bool solve(vector<int>&nums, int sum, int n){
        int t[n+1][sum+1];
        for(int i=0; i<n+1; i++){
            for(int j=0; j<sum+1; j++){
                if(i == 0)t[i][j] = false;
                if(j == 0)t[i][j] = true;
            }
        }

        for(int i=1; i<n+1; i++){
            for(int j=1; j<sum+1; j++){
                if(nums[i-1] <= j){
                    t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        return t[n][sum];
    }

    bool canPartition(vector<int>& nums) {
        int N=nums.size();
         int sum =0; 
        for (int i =0; i<N; i++){
            sum =sum +nums[i];
        }
        
        if(sum %2 !=0){
            return false; 
        }
        else if (sum%2 ==0){
            return solve(nums, sum/2, N);
        }
        return false; 
    }
};