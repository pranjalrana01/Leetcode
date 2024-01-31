#include<bits/stdc++.h>
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
    //    int n = temperatures.size();
    //     vector<int> ans;
    //     stack<int> st;
    //     for(int i=n-1;i>=0;i--){
    //         while(!st.empty() && temperatures[i]>=temperatures[st.top()]){
    //             st.pop();
    //         }
    //         int nd = st.empty() ? 0 : st.top()-i;
    //         ans.push_back(nd);
    //         st.push(i);
    //     }
    //     reverse(ans.begin(),ans.end());
    //     return ans;


    int n = temperatures.size();
    vector<int>ans;
    stack<pair<int,int>>st;

        for(int i= n-1 ; i>=0 ; i--){
            int val = 1;
            int element = temperatures[i];

            if(st.empty()){
                temperatures[i] = 0;
            }
            else{
                while(!st.empty() && st.top().first <= temperatures[i]){
                    val += st.top().second;
                    st.pop();
                }
                (st.empty()) ? temperatures[i] = 0 : temperatures[i] = val;
            }
            st.push({element , val});
        }
        return temperatures;
    }
    
};