class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums;
        sort(nums.begin(),nums.end());
        vector<int> dp(n, 1);
        vector<int> parent(n, -1);
        int ans = 1;
        int index = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if ((nums[i] % nums[j] == 0) &&
                    dp[i] < dp[j] + 1) {
                        
                    dp[i] = dp[j] + 1;
                    parent[i] = j;

                    if (ans < dp[i]) {
                        ans = dp[i];
                        index = i;
                        
                    }
                }
            }
        }

        vector<int> result;
        while (index != -1) {
            result.push_back(nums[index]);
            index = parent[index];
        }

        return result;
    }
};