class Solution {
public:
    string decodeString(string s) {
        stack<int> st;
        stack<string> strst;

        int num = 0;
        string ch = "";

        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            } else if (s[i] == '[') {
                st.push(num);
                strst.push(ch);

                ch = "";
                num = 0;
            } else if (s[i] == ']') {
                int idx = st.top();
                st.pop();

                string temp = strst.top();
                strst.pop();

                for (int j = 0; j < idx; j++) {
                    temp += ch;
                }
                ch = temp;
            } else {
                ch += s[i];
            }
        }
        return ch;
    }
};