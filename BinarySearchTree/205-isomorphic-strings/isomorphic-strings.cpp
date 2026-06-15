class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mpp;
        unordered_map<char, char> mpp2;

        int i = 0, j = 0;
        while (i < s.size() && j < t.size()) {
            if (mpp.find(s[i]) != mpp.end()) {
                if (mpp[s[i]] != t[j]) {
                    return false;
                }
            } else {
                   if(mpp2.find(t[j])!=mpp2.end()){
                    return false;
                   }
                    mpp[s[i]] = t[j];
                    mpp2[t[j]] = s[i];
                
            }
            i++;
            j++;
        }
        return true;
    }
};