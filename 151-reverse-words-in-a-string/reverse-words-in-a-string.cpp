class Solution {
public:
    void reverse(string& s) {
        int start = 0;
        int end = s.size() - 1;
        if (start >= end) {
            return;
        }
        while (start <= end) {
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
    }
    string reverseWords(string s) {
        int n = s.size();
        reverse(s);

        string ans = "";
        string word = "";

        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                if (word.size() > 0) {
                    reverse(word);
                    ans += ' ' + word;
                    word = "";
                }
            } else {
                word += s[i];
            }
        }
        if (word.size() > 0) {
            reverse(word);
            ans += ' ' + word;
        }
        return ans.substr(1);
    }
};