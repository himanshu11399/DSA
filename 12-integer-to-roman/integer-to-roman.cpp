class Solution {
public:
    string intToRoman(int num) {
        vector<int> number = {1000, 900, 500, 400, 100, 90, 50,
                              40,   10,  9,   5,   4,   1};
        vector<string> ch = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                           "XL", "X",  "IX", "V",  "IV", "I"};
        string ans;
        for (int i = 0; i < number.size(); i++) {
            if (num == 0)
                break;
            if (num >= number[i]) {
                int times = num / number[i];
                num = num % number[i];
                for (int j = 0; j < times; j++) {
                    ans += ch[i];
                }
            }
        }
        return ans;
    }
};