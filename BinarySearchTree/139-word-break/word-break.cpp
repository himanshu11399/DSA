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
        bool ans = false;
        for (int i = idx; i < s.size(); i++) {
            string temp = s.substr(idx, i - idx + 1);
            if (st.count(temp)) {
                ans = solve(s, i + 1);
                if (ans == true) {
                    return dp[idx] = ans;
                }
            }
        }
        return dp[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.assign(s.size(), -1);
        for (int i = 0; i < wordDict.size(); i++) {
            st.insert(wordDict[i]);
        }
        return solve(s, 0);
    }
};