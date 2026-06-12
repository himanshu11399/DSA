class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        int maxans = INT_MIN;
        unordered_set<int> st;

        for (int right = 0; right < n; right++) {

            while (st.count(s[right])) {
                st.erase(s[left]);
                left++;
            }

            st.insert(s[right]);
            maxans = max(maxans, right - left + 1);
        }
        return maxans==INT_MIN?0:maxans;
    }
};