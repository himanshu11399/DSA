class Solution {
public:
    vector<int> NSL(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

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
        vector<int> ans(n);
        stack<int>st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }
    int largesthistogram(vector<int>& nums) {
        int n = nums.size();
        vector<int> left = NSL(nums);
        vector<int> right = NSR(nums);
        int maxval = 0;
        for (int i = 0; i < n; i++) {
            int height = nums[i];
            int width = right[i] - left[i] - 1;
            maxval = max(maxval, height * width);
        }
        return maxval;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> nums(m, 0);
        int maxval = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '0') {
                    nums[j] = 0;
                } else {
                    nums[j]+=1;
                }
            }
            int ans = largesthistogram(nums);
            maxval = max(maxval, ans);
        }
        return maxval;
    }
};