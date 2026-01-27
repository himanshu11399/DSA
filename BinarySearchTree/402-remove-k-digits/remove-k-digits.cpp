class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        for (int i = 0; i < num.size(); i++) {
            int val = num[i] - '0';
            while (!st.empty() && k > 0 && st.top() > val) {
                st.pop();
                k--;
            }
            st.push(val);
        }

        while (k != 0) {
            st.pop();
            k--;
        }

        string ans;
        while (!st.empty()) {
            ans.push_back(st.top() + '0');
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        //Remove leading Spaces
        int i=0;
        while(i<ans.size() && ans[i]=='0') i++;
        ans=ans.substr(i);
        return ans.empty()?"0":ans;
    }
};