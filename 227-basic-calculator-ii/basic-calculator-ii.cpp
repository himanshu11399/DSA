class Solution {
public:
    int calculate(string s) {

        int num = 0;
        char operation = '+';
        char curr_char;
        s += '+';
        stack<int> st;

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            } else if (!isdigit(s[i]) && !iswspace(s[i])) {
                if (operation == '+') {
                    st.push(num);
                } else if (operation == '-') {
                    st.push(-num);
                } else if (operation == '*') {
                    int val = st.top();
                    st.pop();
                    st.push(val * num);
                } else if (operation == '/') {
                    int val = st.top();
                    st.pop();
                    st.push(val / num);
                }
                num = 0;
                operation = s[i];
            }
        }

        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};