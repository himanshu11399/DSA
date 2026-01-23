class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {

            // If starting braces so add in the stack
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            } else {
                if (st.empty())
                    return false;
                char ch = st.top();
                if ((s[i] == '}' && ch == '{') || (s[i] == ']' && ch == '[') ||
                    s[i] == ')' && ch == '(') {
                    st.pop();
                    continue;
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};