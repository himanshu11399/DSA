class Solution {
public:
    vector<vector<int>> res;
    void solve(vector<int>& nums, int target, int idx, vector<int>& curr) {
        if (target < 0)
            return;
        if (target == 0) {
            res.push_back(curr);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1])
                continue;

            curr.push_back(nums[i]);
            solve(nums, target - nums[i], i + 1, curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        solve(nums, target, 0, curr);
        return res;
    }
};