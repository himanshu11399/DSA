class Solution {
    public int maxSubArray(int[] nums) {
        int maxans = Integer.MIN_VALUE;
        int j = 0;
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            sum += nums[i];
            maxans = Math.max(maxans, sum);
            if (sum < 0) {
                sum = 0;
                j++;
            }
        }
        return maxans;
    }
}