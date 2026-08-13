class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp;
        stack<int> st;
        vector<int> ans(nums1.size(), -1);

        for (int i = 0; i < nums2.size(); i++) {
            while (!st.empty() && nums2[st.top()] < nums2[i]) {
                mpp[nums2[st.top()]] = nums2[i];
                st.pop();
            }
            st.push(i);
        }

        for (int i = 0; i < nums1.size(); i++) {
            if (mpp.find(nums1[i]) != mpp.end()) {
                ans[i] = mpp[nums1[i]];
            }
        }
        return ans;
    }
};