class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[idx] != nums[i]) {
                idx += 1;
                nums[idx] = nums[i];
            }
        }
        return idx+1;
    }
};