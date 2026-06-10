class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int ans = INT_MIN;
        while (left < right) {
            int h = min(height[left], height[right]);
            int width = right - left;
            ans = max(ans, h * width);
            if (height[left] > height[right]) {
                right--;
            } else {
                left++;
            }
        }
        return ans;
    }
};