class Solution {
public:
    bool ispredecessor(string& a, string& b) {
        if (b.size() != a.size() + 1)
            return false;
        int i = 0, j = 0;
        while (j < b.size()) {
            if (i < a.size() && a[i] == b[j]) {
                i++;
            }
            j++;
        }
        return i == a.size();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        int n = words.size();
        vector<int> dp(n, 1);
        int ans = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (ispredecessor(words[j], words[i]) && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;

                    if (ans < dp[i]) {
                        ans = dp[i];
                    }
                }
            }
        }

        return ans;
    }
};