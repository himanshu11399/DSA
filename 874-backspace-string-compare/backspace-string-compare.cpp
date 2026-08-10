class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int left = s.size() - 1, right = t.size() - 1;

        while (left >= 0 || right >= 0) {

            int skips = 0;
            while (left >= 0) {
                if (s[left] == '#') {
                    skips++;
                    left--;
                } else if (skips > 0) {
                    skips--;
                    left--;
                } else {
                    break;
                }
            }

            int skipt = 0;
            while (right >= 0) {
                if (t[right] == '#') {
                    skipt++;
                    right--;
                } else if (skipt > 0) {
                    skipt--;
                    right--;
                } else {
                    break;
                }
            }

            if (left < 0 && right < 0)
                return true;
            if (left < 0 || right < 0 || s[left] != t[right])
                return false;

            left--;
            right--;
        }
        return true;
    }
};