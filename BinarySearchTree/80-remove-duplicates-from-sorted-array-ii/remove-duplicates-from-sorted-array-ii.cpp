class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;
        int count = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[idx] == nums[i] && count < 2) {
                idx+=1;
                nums[idx]=nums[i];
                count+=1;
            } else if (nums[idx] != nums[i]) {
                idx+=1;
                nums[idx] = nums[i];
                count = 1;
            }
        }
        return idx+1;
    }
};