class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            long long count = 0;
            if (nums[i] == 0) {
                count = 1;
                while (i+1<nums.size() && nums[i] == nums[i + 1]) {
                    count++;
                    i++;
                }
                long long total=(count*(count+1))/2;
                ans+=total;
            }
        }return ans;
    }
};