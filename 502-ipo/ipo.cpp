class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>>proj;
        for(int i=0 ; i<n ; i++){
            proj.push_back({capital[i], profits[i]});
        }

        sort(proj.begin(), proj.end());
        priority_queue<int>profit;
        int j=0;

        for(int i=0 ; i<k ; i++){
            while(j<n && proj[j].first <= w){
                profit.push(proj[j++].second);
            }
            if(profit.empty()){
                break;
            }

            w += profit.top();
            profit.pop();
        }

        return w;
    }
};