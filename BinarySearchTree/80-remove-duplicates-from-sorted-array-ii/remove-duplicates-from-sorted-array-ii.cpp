class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        int k = 2;
        int prev = nums[0];
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] && nums[i] == prev) {
                prev = nums[i - 1];
                continue;
            } else {
                prev = nums[i - 1];
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};