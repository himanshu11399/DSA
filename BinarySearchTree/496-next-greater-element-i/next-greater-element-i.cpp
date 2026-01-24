class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> mpp;
        stack<int> st;
        for (int i = nums2.size() - 1; i >= 0; i--) {
            if (i == nums2.size() - 1) {
                mpp[nums2[i]] = -1;
            } else {
                while (!st.empty() && st.top() < nums2[i]) {
                    st.pop();
                }
                if (st.empty()) {
                    mpp[nums2[i]] = -1;
                } else {
                    mpp[nums2[i]] = st.top();
                }
            }
            st.push(nums2[i]);
        }

        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(mpp[nums1[i]]);
        }
        return ans;
    }
};