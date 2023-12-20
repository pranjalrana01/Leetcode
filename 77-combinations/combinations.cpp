class Solution {
public:
    void help(int i, int n, int k, vector<int>& subset, vector<vector<int>>& ans){
        if(i > n){
            if(k == 0){
                ans.push_back(subset);
            }
            return;
        }

        subset.push_back(i);
        help(i+1, n, k-1, subset, ans);

        subset.pop_back();
        help(i+1, n,k, subset, ans);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>subset;

        help(1,n, k, subset, ans);
        return ans;
    }
};