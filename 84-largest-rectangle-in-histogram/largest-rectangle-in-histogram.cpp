class Solution {
public:
    vector<int> NSL(vector<int>& heights) {
        vector<int> left;
        int n = heights.size();
        int pseudoindex = -1;
        stack<pair<int,int>> stk;
        for (int i = 0; i < n; i++) {
            while (!stk.empty() && stk.top().first >= heights[i]) {
                stk.pop();
            }
            if (stk.empty()) {
                left.push_back(pseudoindex);
            } else {
                left.push_back(stk.top().second);
            }
            stk.push({heights[i], i});
        }
        return left;
    }

    vector<int> NSR(vector<int>& heights) {
        vector<int> right;
        int n = heights.size();
        int pseudoindex = n;

        stack<pair<int,int>> s;

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && s.top().first >= heights[i]) {
                s.pop();
            }
            if (s.empty()) {
                right.push_back(pseudoindex);
            } else {
                right.push_back(s.top().second);
            }
            s.push({heights[i], i});
        }
        reverse(right.begin(), right.end()); // Correct the order
        return right;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left = NSL(heights);
        vector<int> right = NSR(heights);
        vector<int> width(n);
        vector<int> area(n);

        for (int i = 0; i < n; i++) {
            width[i] = right[i] - left[i] - 1;
        }

        for (int i = 0; i < n; i++) {
            area[i] = width[i] * heights[i];
        }

        int maxi = 0; // Initialize to 0 instead of -23
        for (int i = 0; i < n; i++) {
            if (area[i] > maxi) {
                maxi = area[i];
            }
        }
        return maxi;
    }
};