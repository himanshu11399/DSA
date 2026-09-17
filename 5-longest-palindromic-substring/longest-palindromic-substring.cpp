class Solution {
public:
    bool ischeck(string& s, int i, int j) {
        if (i >= j) {
            return true;
        }
        if (s[i] != s[j])
            return false;
        return ischeck(s, i + 1, j - 1);
    }
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--) {
                if (ischeck(s, i, j) && cnt < j - i + 1) {
                    ans = s.substr(i, j - i + 1);
                    cnt = j - i + 1;
                }
            }
        }
        return ans;
    }
};