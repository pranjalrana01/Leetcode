// class Solution {
// public:
    
//     void solve(vector<string>& ans, string op, int open, int close){
//         if(open == 0 && close == 0){
//             ans.push_back(op);
//             return;
//         }

//         if(open == close || close == 0){
//             string op1 = op;
//             op1.push_back('(');
//             solve(ans, op1, open-1, close);
//         }

//         else if(open == 0){
//             string op1 = op;
//             op1.push_back(')');
//             solve(ans, op1, open, close-1);
//         }

//         else{
//             string op1 = op;
//             string op2 = op;
//             op1.push_back('(');
//             op2.push_back(')');
//             solve(ans, op1, open-1, close);
//             solve(ans, op2, open, close-1);
//         }
//     }
    
//     vector<string> generateParenthesis(int n) {
//         int open = n;
//         int close = n;
//         string op="";
//         vector<string>ans;
//         solve(ans, op, open, close);
//         return ans;
//     }
// };

class Solution {
public:
    vector<string>v;
    void solve(int i , int j , int n , string s) {
        if(i == j and i == n) {
            v.push_back(s);
            return;
        }
        if(i < n) solve(i + 1 , j , n , s + '(');
        if(j < i) solve(i  , j + 1 , n , s + ')');

    }
    vector<string> generateParenthesis(int n) {
        v.clear();
        solve(0, 0 , n , "");
        return v;
    }
};