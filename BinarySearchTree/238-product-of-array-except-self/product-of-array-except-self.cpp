class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);

        // calculate Prefix;
        int pre = nums[0];
        prefix[0] = pre;
        for (int i = 1; i < n; i++) {
            prefix[i] = pre * nums[i];
            pre = prefix[i];
        }

        int suff = nums[n - 1];
        suffix[n - 1] = suff;
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suff * nums[i];
            suff = suffix[i];
        }

        vector<int> ans(n);
        ans[0] = suffix[1];
        ans[n - 1] = prefix[n - 2];
        for (int i = 1; i < n - 1; i++) {
            ans[i] = prefix[i - 1] * suffix[i + 1];
        }
        return ans;
    }
};