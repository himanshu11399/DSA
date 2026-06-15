class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mpp;
        unordered_map<string, char> mpp2;

        vector<string> str;

        for (int i = 0; i < s.size(); i++) {
            string word;
            while (i < s.size() && s[i] != ' ') {
                word += s[i];
                i++;
            }
            str.push_back(word);
        }

        if (pattern.size() != str.size()) {
            return false;
        }

        int i = 0, j = 0;
        while (i < pattern.size() && j < str.size()) {
            if (mpp.find(pattern[i]) != mpp.end()) {
                if (mpp[pattern[i]] != str[j]) {
                    return false;
                }
            } else {
                if (mpp2.find(str[j]) != mpp2.end()) {
                    return false;
                }
                mpp[pattern[i]] = str[j];
                mpp2[str[j]] = pattern[i];
            }
            i++;
            j++;
        }
        return true;
    }
};