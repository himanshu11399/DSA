class Solution {
public:
    unordered_set<string> st;
    vector<int> dp;
    bool solve(string& s, int idx) {
        if (idx >= s.size()) {
            return true;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        bool result=false;
        for (int i = idx; i < s.size(); i++) {
            string str = s.substr(idx, i - idx + 1);
            if (st.count(str)) {
                result =result || solve(s, idx + (i - idx + 1));
            }
        }
        return dp[idx] = result;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for (int i = 0; i < wordDict.size(); i++) {
            st.insert(wordDict[i]);
        }
        dp.assign(s.size(), -1);
        return solve(s, 0);
    }
};