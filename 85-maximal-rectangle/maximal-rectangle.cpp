class Solution {
public:
vector<int>NSL(vector<int>& heights){
        vector<int>left;
        int n = heights.size();
        int pseudoindex = -1;
        stack<pair<int,int>>stk;
        for(int i=0 ; i<n ; i++){
            if(stk.empty()){
                left.push_back(pseudoindex);
            }
            else if(stk.size() > 0 && stk.top().first < heights[i]){
                left.push_back(stk.top().second);
            }
            else if(stk.size() > 0 && stk.top().first >= heights[i]){
                while(stk.size() > 0 && stk.top().first >= heights[i]){
                    stk.pop();
                }
                if(stk.size() == 0)left.push_back(pseudoindex);
                else{
                    left.push_back(stk.top().second);
                }
            }
            stk.push({heights[i] , i});
        }
        return left;
    }

       vector<int>NSR(vector<int>& heights){
           vector<int>right;
           int n  = heights.size();
           stack<pair<int,int>>s;
           int pseudoindex = n;

           for(int i= n-1 ; i>=0 ; i--){
               if(s.size() == 0){
                   right.push_back(pseudoindex);
               }
               else if(s.size() > 0 && s.top().first < heights[i]){
                   right.push_back(s.top().second);
               }
                else if(s.size() > 0 && s.top().first >= heights[i]){
                    while(s.size() > 0 && s.top().first >= heights[i]){
                        s.pop();
                    }
                    if(s.size() == 0){
                        right.push_back(pseudoindex);
                    }
                    else{
                        right.push_back(s.top().second);
                    }
                }
                s.push({heights[i], i});
           }
           reverse(right.begin(), right.end());
           return right;
       }

  int largestRectangleArea(vector<int>& heights) {

      //solution 1
        int n = heights.size();
        vector<int>left = NSL(heights);
        vector<int>right = NSR(heights);
        vector<int>width(n);
        vector<int>area(n);
        for(int i=0 ; i<n ; i++){
            width[i] = right[i] - left[i] - 1;
        }

        for(int i=0; i <n ; i++){
            area[i] = width[i] * heights[i];
        }
        int maxi = -23;
        for(int i = 0;i <n ; i++){
            if(area[i] > maxi){
                maxi = area[i];
            }
        }
        return maxi;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
         if (matrix.empty()) {
            return 0;
        }
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> v(col, 0);
        int maxi = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == '0') {
                    v[j] = 0;
                } else {
                    v[j] += 1;
                }
            }
            maxi = max(maxi, largestRectangleArea(v));
        }
        return maxi;
    }
};