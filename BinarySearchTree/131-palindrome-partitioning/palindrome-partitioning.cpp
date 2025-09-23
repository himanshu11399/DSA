class Solution {
public:
    vector<vector<string>> res;
    bool ispalidrome(string s) {
        int low = 0, high = s.size()-1;
        while (low < high) {
            if (s[low] != s[high])
                return false;
            low++;
            high--;
        }
        return true;
    }

    void solve(string s, vector<string>& partition) {
        if (s.size() == 0) {
            res.push_back(partition);
            return;
        }

        for (int i = 0; i < s.size(); i++) {
            string path = s.substr(0, i + 1);
            if (ispalidrome(path)) {
                partition.push_back(path);
                solve(s.substr(i + 1), partition);
                partition.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>st;
        solve(s, st);
        return res;
    }
};