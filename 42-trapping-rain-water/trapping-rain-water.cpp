class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);

        int pre = 0;

        for (int i = 0; i < n; i++) {
            prefix[i] = max(nums[i], pre);
            pre = max(pre, nums[i]);
        }

        int suf = 0;

        for (int j = n - 1; j >= 0; j--) {
            suffix[j] = max(suf, nums[j]);
            suf = max(suf, nums[j]);
        }

        int maxans = 0;
        for (int i = 0; i < n; i++) {
            maxans += min(prefix[i], suffix[i]) - nums[i];
        }
        return maxans;
    }
};