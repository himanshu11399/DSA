class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size())
            return "";

        unordered_map<char, int> mpp;
        for (auto it : t) {
            mpp[it]++;
        }

        int start = -1, len = INT_MAX;
        int i = 0, count = t.size();

        for (int j = 0; j < s.size(); j++) {

            // Insert
            if (mpp[s[j]] > 0) {
                count--;
            }
            mpp[s[j]]--;

            // check
            if (count == 0) {
                // shrink
                while (count==0) {
                    if (len > j - i + 1) {
                        len = j - i + 1;
                        start = i;
                    }
                    mpp[s[i]]++;
                
                    if (mpp[s[i]] > 0) {
                        count++;
                    }
                    i++;
                }
            }
        }

        if (start == -1) {
            return "";
        }
        return s.substr(start, len);
    }
};