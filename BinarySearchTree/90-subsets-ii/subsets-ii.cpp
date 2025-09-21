class Solution {
public:
    vector<vector<int>> res;
    void solve(vector<int> nums, int idx, vector<int>& curr) {
            res.push_back(curr);
        
        for (int i = idx; i < nums.size(); i++) {
            if (i > idx && nums[i] == nums[i - 1]) {
                continue;
            }
            curr.push_back(nums[i]);
            solve(nums, i + 1, curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> curr;
        solve(nums, 0, curr);
        return res;
    }
};