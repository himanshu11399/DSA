class Solution {
public:
    string simplifyPath(string s) {
        stack<string> st;

        string ch;
        int cnt = 0;
        s+='/';

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '/') {

                if (!ch.empty()) {
                    if(cnt==1 && ch=="."){

                    }
                    else if (cnt == 2 && ch=="..") {
                        if (!st.empty())
                            st.pop();
                    } else{
                        st.push(ch);
                    }
                }
                ch = "";
                cnt = 0;

            } else if (s[i] == '.') {
                ch += s[i];
                cnt++;
            } else {
                ch += s[i];
                cnt=0;
            }
        }

        // Creating Path
        string ans = "";
        while (!st.empty()) {
            ans = '/' + st.top() + ans;
            st.pop();
        }
        return ans.size() == 0 ? "/" : ans;
    }
};