class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> s;
        vector<int> v;
        for(int i = n-1;i >= 0; i--){
            s.push(nums[i]);
        }
        for(int i = n-1; i >= 0; i--){
            if(s.empty()){
                v.push_back(-1);
            }else if(!s.empty() && nums[i] >= s.top()){
                while(!s.empty() && nums[i] >= s.top()){
                    s.pop();
                }
                if(s.size() == 0){
                    v.push_back(-1);
                }else{
                    v.push_back(s.top());
                }
            }else if(!s.empty() && nums[i] < s.top()){
                v.push_back(s.top());
            }
            s.push(nums[i]);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};