class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int limit = nums.size() / 2;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
            if (mpp[nums[i]] > limit) {
                return nums[i];
            }
        }
        return -1;
    }
};