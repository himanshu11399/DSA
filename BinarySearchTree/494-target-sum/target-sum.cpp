class Solution {
public:
    unordered_map<string,int>mpp;
    int solve(vector<int> nums, int i, int currsum, int target) {
        if (i == nums.size()) {
            if (target == currsum) {
                return 1;
            } else {
                return 0;
            }
        }
        string key=to_string(i)+"_"+to_string(currsum);
        if(mpp.count(key)){
            return mpp[key];
        }

        int add = solve(nums, i + 1, currsum + nums[i], target);
        int sub = solve(nums, i + 1, currsum - nums[i], target);

        return mpp[key]=add + sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, 0, 0, target);
    }
};