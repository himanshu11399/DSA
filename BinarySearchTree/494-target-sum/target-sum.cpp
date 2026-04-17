class Solution {
public:
    // unordered_map<string,int>mpp;
    int sum = 0;
    vector<vector<int>>dp;
    int solve(vector<int> nums, int i, int currsum, int target) {
        if (i == nums.size()) {
            if (target == currsum) {
                return 1;
            } else {
                return 0;
            }
        }
        // string key=to_string(i)+"_"+to_string(currsum);
        // if(mpp.count(key)){
        //     return mpp[key];
        // }

        if(dp[i][currsum+sum]!=-1){
            return dp[i][currsum+sum];
        }

        int add = solve(nums, i + 1, currsum + nums[i], target);
        int sub = solve(nums, i + 1, currsum - nums[i], target);

        // return mpp[key]=add + sub;
        return dp[i][currsum + sum] = add + sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        dp.assign(n + 1, vector<int>(2 * sum+1, -1));
        return solve(nums, 0, 0, target);
    }
};