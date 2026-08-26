class Solution {
public:
    bool isValid(string s) {
        int n = s.size();

        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            } else {
                if (st.empty()) {
                    return false;
                } else if ((st.top() == '(' && ch == ')') ||
                           (st.top() == '[' && ch == ']') ||
                           st.top() == '{' && ch == '}') {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        if (!st.empty())
            return false;
        return true;
    }
};