class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        if (p.size() > s.size())
            return ans;

        unordered_map<char, int> mpp;
        for (auto it : p) {
            mpp[it]++;
        }

        int count = p.size();
        int i = 0;

        for (int j = 0; j < s.size(); j++) {

            if (mpp[s[j]] > 0) {
                count--;
            }
            mpp[s[j]]--;

            // Ensure the Size of the Window
            if (j - i + 1 > p.size()) {
                if (mpp[s[i]] >= 0) {
                    count++;
                }
                mpp[s[i]]++;
                i++;
            }

            //Check the anagram
            if(count==0 && j-i+1==p.size()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};