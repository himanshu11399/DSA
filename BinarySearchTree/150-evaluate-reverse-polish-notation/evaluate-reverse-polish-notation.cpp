class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (int i = 0; i < tokens.size(); i++) {
            string ch = tokens[i];
            if (ch == "+" || ch == "-" || ch == "*" || ch == "/") {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                if (ch == "+") {
                    st.push(second + first);
                } else if (ch == "-") {
                    st.push(second - first);
                } else if (ch == "*") {
                    st.push(second * first);
                } else {
                    st.push(second / first);
                }
            } else {
                st.push(stoi(ch));
            }
        }
        return st.top();
    }
};