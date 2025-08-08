class Solution {
public:
    int romanToInt(string s) {
        vector<int> number = {1000, 900, 500, 400, 100, 90, 50,
                              40,   10,  9,   5,   4,   1};
        vector<string> ch = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                             "XL", "X",  "IX", "V",  "IV", "I"};

        map<string, int> mpp;
        for (int i = 0; i < number.size(); i++) {
            mpp[ch[i]] = number[i];
        }

        int ans = 0;
        for (int i = 0; i < s.size();) {
            if (i + 1 < s.size() && mpp.find(s.substr(i, 2)) != mpp.end()) {
                ans += mpp[s.substr(i, 2)];
                i += 2;
            } else {
                ans += mpp[s.substr(i, 1)];
                i++;
            }
        }
        return ans;
    }
};