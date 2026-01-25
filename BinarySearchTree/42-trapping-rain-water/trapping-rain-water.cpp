class Solution {
public:
    int trap(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        vector<int> lmax(n, 0);
        vector<int> rmax(n, 0);

        // fill lmax (strictly left)
        int leftmax = nums[0];
        for (int i = 1; i < n; i++) {
            lmax[i] = leftmax;
            leftmax = max(leftmax, nums[i]);
        }

        // fill rmax (strictly right)
        int rightmax = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rmax[i] = rightmax;
            rightmax = max(rightmax, nums[i]);
        }

        int maxwater = 0;
        for (int i = 0; i < n; i++) {
            int water = min(lmax[i], rmax[i]) - nums[i];
            if (water > 0)
                maxwater += water;
        }

        return maxwater;
    }
};
