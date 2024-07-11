
class Solution {
public:
    void push_string(const string &sample, stack<char> &st) {
        for (char ch : sample) {
            st.push(ch);
        }
    }

    string reverseParentheses(string s) {
        stack<char> st;
        for (char ch : s) {
            if (ch == ')') {
                string sample;
                while (!st.empty() && st.top() != '(') {
                    sample.push_back(st.top());
                    st.pop();
                }
                if (!st.empty() && st.top() == '(') {
                    st.pop(); // remove the '('
                }
                push_string(sample, st);
            } else {
                st.push(ch);
            }
        }

        string result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
