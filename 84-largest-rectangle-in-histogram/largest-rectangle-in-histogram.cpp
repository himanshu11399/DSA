class Solution {
public:
    vector<int> NSL(vector<int>& nums) {
        vector<int> ans(nums.size());
        stack<int> st;

        for (int i = 0; i < nums.size(); i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> NSR(vector<int>& nums) {
        vector<int> ans(nums.size());
        stack<int> st;

        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? nums.size() : st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        vector<int> left = NSL(nums);
        vector<int> right = NSR(nums);
        int maxarea = 0;

        for (int i = 0; i < n; i++) {
            int width = (right[i] - left[i] - 1);
            int height = nums[i];
            int area = width * height;
            maxarea = max(maxarea, area);
        }
        return maxarea;
    }
};