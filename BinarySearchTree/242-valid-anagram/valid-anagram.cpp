class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mpp;
        for (int i = 0; i < s.size(); i++) {
            mpp[s[i]]++;
        }
        for (int i = 0; i < t.size(); i++) {
            if (mpp.find(t[i]) != mpp.end()) {
                if (mpp[t[i]] > 0) {
                    mpp[t[i]]--;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
        for (auto it : mpp) {
            if (mpp[it.first] > 0) {
                return false;
            }
        }
        return true;
    }
};
