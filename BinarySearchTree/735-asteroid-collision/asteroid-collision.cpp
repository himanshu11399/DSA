class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int> st;
        for (int i = 0; i < nums.size(); i++) {
            bool iscollide = false;
            while (!st.empty() && nums[i] < 0 && nums[st.top()] > 0) {
                int sum = nums[st.top()] + nums[i];
                if (sum > 0) {
                    iscollide = true;
                    break;
                } else if (sum < 0) {
                    st.pop();
                } else {
                    iscollide = true;
                    st.pop();
                    break;
                }
            }
            if (!iscollide) {
                st.push(i);
            }
        }
        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(nums[st.top()]);
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};