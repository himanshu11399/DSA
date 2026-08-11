class Solution {
public:
    int calculate(string s) {
        stack<int> st;

        int result = 0;
        long long num = 0;
        int sign = 1;

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                if(num>INT_MAX) return INT_MAX;
                num = num * 10 + (s[i] - '0');
            } else if (s[i] == '+') {
                result += sign * num;
                num = 0;
                sign = 1;
            } else if (s[i] == '-') {
                result += sign * num;
                num = 0;
                sign = -1;
            } else if (s[i] == '(') {
                st.push(result);
                st.push(sign);

                result = 0;
                sign = 1;
            } else if (s[i] == ')') {
                result += num * sign;
                num = 0;

                int prevSign = st.top();
                st.pop();

                int prev_val = st.top();
                st.pop();

                result = prev_val + prevSign * result;
            }
        }
        result += num * sign;
        return result;
    }
};