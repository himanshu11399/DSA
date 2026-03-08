class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1);
        vector<int> sufix(n, 1);
        vector<int> ans(n, 1);

        int preffix = 1;
        for (int i = 0; i < n; i++) {
            prefix[i] = preffix;
            preffix = preffix * nums[i];
        }

        int suffix = 1;
        for (int i = nums.size()-1; i >= 0; i--) {
            sufix[i] = suffix;
            suffix = suffix * nums[i];
        }

        for (int i = 0; i < n; i++) {
            ans[i] = prefix[i] * sufix[i];
        }

        return ans;
    }
};