class Solution {
public:
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size() - 1;
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u'};

        while (left <= right) {
            if (st.count(tolower(s[left])) > 0 &&
                st.count(tolower(s[right])) > 0) {
                swap(s[left], s[right]);
                left++;
                right--;
            } else if (st.count(tolower(s[left])) > 0) {
                right--;
            } else if (st.count(tolower(s[right])) > 0) {
                left++;
            } else {
                left++;
                right--;
            }
        }
        return s;
    }
};