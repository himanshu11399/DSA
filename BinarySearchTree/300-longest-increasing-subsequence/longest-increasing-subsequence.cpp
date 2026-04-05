class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        int maxans = 1;
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] > nums[j]) {
                    ans[i] = max(ans[i], ans[j] + 1);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            maxans = max(maxans, ans[i]);
        }
        return maxans;
    }
};