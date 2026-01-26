class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int abs = INT_MAX;
        for (int i = 1; i < n; i++) {
            int a = nums[i - 1];
            int b = nums[i];
            abs = min(abs, (b - a));
        }
        vector<vector<int>> ans;
        set<int> st;
        for (int i = 0; i < n; i++) {
            int diff = nums[i] - abs;
            if (st.find(diff) != st.end()) {
                int a = diff;
                int b = nums[i];
                if (a > b) {
                    ans.push_back({b, a});
                } else {
                    ans.push_back({a, b});
                }
            }
            st.insert(nums[i]);
        }
        return ans;
    }
};