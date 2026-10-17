class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> rotate(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            rotate[(i + k) % nums.size()] = nums[i];
        }
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = rotate[i];
        }
    }
};