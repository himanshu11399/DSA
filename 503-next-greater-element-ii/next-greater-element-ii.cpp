class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> ans(nums.size(), -1);
        int n = nums.size();

        for (int i = 0; i < 2 * nums.size() - 1; i++) {
            while (!st.empty() && nums[st.top()%n] < nums[i%n]) {
                ans[st.top()%n] = nums[i%n];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};