#include<bits/stdc++.h>
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       int n = temperatures.size();
        vector<int> ans;
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && temperatures[i]>=temperatures[st.top()]){
                st.pop();
            }
            int nd = st.empty() ? 0 : st.top()-i;
            ans.push_back(nd);
            st.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};