class Solution {
    public boolean solve(char[] nums) {
        int start = 0, end = nums.length - 1;

        while (start < end) {
            if (!Character.isLetterOrDigit(nums[start])) {
                start++;
            } else if (!Character.isLetterOrDigit(nums[end])) {
                end--;
            } else if (Character.toLowerCase(nums[start]) != Character.toLowerCase(nums[end])) {
                return false;
            } else {
                start++;
                end--;
            }
        }
        return true;
    }

    public boolean isPalindrome(String s) {
        int n = s.length();

        char[] nums = s.toCharArray();
        return solve(nums);
    }
}