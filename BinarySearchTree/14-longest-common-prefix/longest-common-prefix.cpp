class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        int n = s.size();
        string startString = s[0];
        string ans = "";

        for (int i = 0; i < startString.size(); i++) {
            for (int j = 1; j < s.size(); j++) {
                string nextStr = s[j];
                if (startString[i] != nextStr[i]) {
                    return ans;
                }
            }
            ans += startString[i];
        }
        return ans;
    }
};