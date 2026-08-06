class Solution {
public:
    int minDeletions(string s) {
        map<char, int> mpp;
        for (auto it : s) {
            mpp[it]++;
        }
        int ans = 0;
        unordered_set<int> st;
        for (auto it : mpp) {
            int num = it.second;
            while (st.find(num) != st.end()) {
                num--;
                ans++;
            }
            if (num != 0) {
                st.insert(num);
            }
        }
        return ans;
    }
};