class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int total = 0;

        int idx = n - 1;
        // Remove all white spaces at end
        while (s[idx] == ' ') {
            idx--;
        }

        for (int i = idx; i >= 0; i--) {
            if (s[i] == ' ') {
                break;
            } else {
                total++;
            }
        }
        return total;
    }
};