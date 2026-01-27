class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for (int left = 0; left < n; left++) {
            int minval = nums[left], maxval = nums[left];
            for (int right = left; right < n; right++) {
                minval = min(minval, nums[right]);
                maxval = max(maxval, nums[right]);
                ans += maxval - minval;
            }
        }
        return ans;
    }
};