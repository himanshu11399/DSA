class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wsize = words[0].size();
        int total = words.size() * wsize;
        unordered_map<string, int> mpp;
        unordered_map<string,int>need;
        vector<int> ans;
        for(int i=0;i<words.size();i++){
            need[words[i]]++;
        }

        for (int left = 0; left + total <= s.size(); left++) {
            string str = s.substr(left, total);

            for (int j = 0; j + wsize <= str.size(); j+=wsize) {
                string val = str.substr(j, wsize);
                mpp[val]++;
            }

            if(mpp==need){
                ans.push_back(left);
            }
            mpp.clear();
        }
        return ans;
    }
};
