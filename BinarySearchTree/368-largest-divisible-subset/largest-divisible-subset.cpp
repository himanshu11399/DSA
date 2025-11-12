class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int lastIdx = 0, lis = 0;
        vector<int> dp(n, 1);
        vector<int> parent(n, -1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                    if (lis < dp[i]) {
                        lis = dp[i];
                        lastIdx = i;
                    }
                }
            }
        }

        vector<int>result;
        while(lastIdx!=-1){
            result.push_back(nums[lastIdx]);
            lastIdx=parent[lastIdx];
        }
        reverse(result.begin(),result.end());
        return result;
    }
};