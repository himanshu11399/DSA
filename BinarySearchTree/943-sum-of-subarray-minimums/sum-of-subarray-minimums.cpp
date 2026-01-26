class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        vector<int> NSR(n, n);
        vector<int> NSL(n, -1);
        long long mod = 1e9 + 7;

        // Fill the NSL
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                NSL[i] = st.top();
            }
            st.push(i);
        }

        // Clean the Stack
        while (!st.empty()) {
            st.pop();
        }

        // Fill NSR
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                NSR[i] = st.top();
            }
            st.push(i);
        }

        // calculate answer
        long long maxans = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - NSL[i];
            long right = NSR[i] - i;
            long long ways=left*right;
            long long sum=ways*nums[i];
            maxans =(maxans+sum)%mod;
        }
        return maxans;
    }
};