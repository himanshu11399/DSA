class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& nums, int l, int h) {
        if (dp[l][h] != -1)
            return dp[l][h];
        int ans = INT_MIN;
        for (int i = l; i <= h; i++) {
            int a = 0, b = 0;
            // For left
            if (i - 1 >= l) {
                a = solve(nums, l, i - 1);
            } else {
                a = 0;
            }

            // For right
            if (i + 1 <= h) {
                b = solve(nums, i + 1, h);
            } else {
                b =0;
            }
            ans = max(ans, nums[l- 1] * nums[i] * nums[h + 1] + a + b);
        }
        return dp[l][h] = ans;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        dp.assign(n, vector<int>(n, -1));
        return solve(nums, 1, n - 2);
    }
};