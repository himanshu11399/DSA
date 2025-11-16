class Solution {
public:
    vector<vector<int>> dp;
    int solve(int l, int h, vector<int>& cuts) {
        if (h - l < 2)
            return 0;
        if (dp[l][h] != -1)
            return dp[l][h];

        int mini = 1e9;
        for (int i = l + 1; i < h; i++) {
            int sum = solve(l, i, cuts) + solve(i, h, cuts);
            int cost = (cuts[h] - cuts[l]) + sum;
            mini = min(mini, cost);
        }
        return dp[l][h] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(begin(cuts), 0);
        cuts.push_back(n);
        dp.assign(cuts.size(), vector<int>(cuts.size(), -1));
        return solve(0, cuts.size() - 1, cuts);
    }
};