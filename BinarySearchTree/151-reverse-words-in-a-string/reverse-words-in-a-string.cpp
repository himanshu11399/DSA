class Solution {
public:
    string reverseWords(string s) {

        string token = "";
        stringstream ss(s);
        vector<string> word;
        while (ss >> token) {
            word.push_back(token);
        }

        string ans = "";
        for (int i = word.size() - 1; i >= 0; i--) {
            ans += word[i];
            if (i != 0)
                ans += ' ';
        }
        return ans;
    }
};