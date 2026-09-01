class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[idx] == nums[i]) {
                count += 1;
                if (count == 2) {
                    idx += 1;
                    nums[idx] = nums[i];
                }
            } else {
                count=1;
                idx += 1;
                nums[idx] = nums[i];
            }
        }
        return idx+1;
    }
};