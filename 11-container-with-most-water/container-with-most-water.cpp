class Solution {
public:
    int maxArea(vector<int>& nums) {
        int maxans = 0;
        int left = 0, right = nums.size() - 1;

        while (left <right) {
            int h = min(nums[left], nums[right]);
            maxans = max(maxans, (right - left) * h);
            if (nums[left] >= nums[right]) {
                right--;
            } else {
                left++;
            }
        }
        return maxans;
    }
};