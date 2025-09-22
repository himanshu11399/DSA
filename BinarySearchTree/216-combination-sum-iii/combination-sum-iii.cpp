class Solution {
public:
    vector<vector<int>> res;
    void solve(int i, int k, int sum, vector<int>& curr, int n) {
        if (sum == n) {
            if (k == 0) {
                res.push_back(curr);
            }
            return;
        }
        if (k < 0 || i == 10)
            return;

        // Include
        curr.push_back(i);
        solve(i + 1, k - 1, sum + i, curr, n);
        curr.pop_back();

        // Exclude
        solve(i + 1, k, sum, curr, n);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        solve(1, k, 0, curr, n);
        return res;
    }
};