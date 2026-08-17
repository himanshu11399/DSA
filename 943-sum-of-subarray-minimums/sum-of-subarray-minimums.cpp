class Solution {
public:
    vector<int> NLL(vector<int>& nums) {
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
    vector<int> NLR(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n);
        for (int i = n-1; i >=0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }

    int sumSubarrayMins(vector<int>& nums) {
        int n=nums.size();
        int MOD=1e9+7;

        vector<int>left=NLL(nums);
        vector<int>right=NLR(nums);

        int ans=0;

        for(int i=0;i<nums.size();i++){
            long long leftcount=i-left[i];
            long long rightcount=right[i]-i;
            long long con=(leftcount*rightcount % MOD)*nums[i] % MOD;
            ans=(ans+con)%MOD;
        }
        return ans;
    }
};