class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int maxprofit = 0;
        int idx = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[idx] > nums[i]) {
                idx=i;
            } else {
                maxprofit = max(maxprofit, nums[i] - nums[idx]);
            }
        }
        return maxprofit;
    }
};