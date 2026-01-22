class Solution {
public:
    int minPairsum(vector<int>& nums) {
        int idx;
        int minsum = INT_MAX;
        for (int i = 1; i < nums.size(); i++) {
            int sum = nums[i] + nums[i - 1];
            if (minsum > sum) {
                minsum = sum;
                idx = i - 1;
            }
        }
        return idx;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int oper = 0;
        while (!is_sorted(nums.begin(), nums.end())) {
            int idx = minPairsum(nums);
            nums[idx] = nums[idx] + nums[idx + 1];
            nums.erase(nums.begin() + idx + 1);
            oper++;
        }
        return oper;
    }
};