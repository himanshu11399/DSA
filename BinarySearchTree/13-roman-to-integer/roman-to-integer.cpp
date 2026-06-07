class Solution {
public:
    int romanToInt(string s) {
        vector<int> value = {1000, 500, 100, 50, 10,  5,  1,
                             4,    9,   40,  90, 400, 900};
        vector<string> symbol = {"M",  "D",  "C",  "L",  "X",  "V", "I",
                                 "IV", "IX", "XL", "XC", "CD", "CM"};

        unordered_map<string, int> mpp;
        for (int i = 0; i < value.size(); i++) {
            mpp[symbol[i]] = value[i];
        }

        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i + 1 < s.size() && mpp.find(s.substr(i, 2)) != mpp.end()) {
                ans += mpp[s.substr(i, 2)];
                i++;
            } else {
                ans += mpp[s.substr(i, 1)];
            }
        }
        return ans;
    }
};