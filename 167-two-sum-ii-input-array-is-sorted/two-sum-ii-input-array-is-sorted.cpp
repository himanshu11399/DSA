class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            int total = nums[i] + nums[j];
            if (total == target) {
                return {i + 1, j + 1};
            } else if (total > target) {
                j--;
            } else {
                i++;
            }
        }
        return {-1, -1};
    }
};