class Solution {
public:
    bool isValid(string& s, int i, int j) {
        if (i >= j) {
            return true;
        }
        if (s[i] != s[j]) {
            return false;
        }
        return isValid(s, i + 1, j - 1);
    }
    string longestPalindrome(string s) {
        int n = s.size();
        int len = 0;
        string ans = "";

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                if (isValid(s, i, j)) {
                    if (len < j - i + 1) {
                        len = j - i + 1;
                        ans = s.substr(i, j - i + 1);
                    }
                }

            }
        }

        return ans;
    }
};