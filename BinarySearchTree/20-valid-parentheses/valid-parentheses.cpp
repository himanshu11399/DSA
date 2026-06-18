class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            char sym = s[i];
            if (sym == '(' || sym == '{' || sym == '[') {
                st.push(sym);
            } else {
                if (st.empty()) {
                    return false;
                } else if ((st.top() == '(' && sym == ')') ||
                           (st.top() == '[' && sym == ']') ||
                           (st.top() == '{' && sym == '}')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        if (!st.empty()) {
            return false;
        }
        return true;
    }
};