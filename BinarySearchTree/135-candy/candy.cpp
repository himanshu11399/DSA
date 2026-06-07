class Solution {
public:
    int candy(vector<int>& nums) {
        int n = nums.size();
        vector<int> candies(n, 1);

        // Use left Rule
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Use Right Rule
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > nums[i + 1]) {
                if (candies[i] <= candies[i + 1]) {
                    candies[i] = candies[i + 1] + 1;
                }
            }
        }

        int total = 0;
        for (int i = 0; i < n; i++) {
            total += candies[i];
        }
        return total;
    }
};