class Solution {
public:
    vector<int> NSL(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> NSR(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        vector<int> NSLeft = NSL(nums);
        vector<int> NSRight = NSR(nums);
        int maxval = INT_MIN;
        for (int i = 0; i < n; i++) {
            int height = nums[i];
            int left = NSLeft[i];
            int right = NSRight[i];
            int width = right - left - 1;
            maxval = max(maxval, height * width);
        }
        return maxval;
    }
};