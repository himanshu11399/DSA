class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mpp;
        int start = -1;

        for (int i = 0; i < s.size(); i++) {
            mpp[s[i]]++;
        }

        for (int i = 0; i < s.size(); i++) {
            if (mpp[s[i]] == 1) {
                start = i;
                break;
            }
        }

        return start;
    }
};