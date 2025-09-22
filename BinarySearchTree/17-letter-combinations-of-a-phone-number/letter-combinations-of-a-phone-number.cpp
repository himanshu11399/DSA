class Solution {
public:
    vector<string> res;
     unordered_map<char, string> mpp;

    void solve(string digits,int idx,string ans) {
        if(idx==digits.size()){
            res.push_back(ans);
            return;
        }

        string letter=mpp[digits[idx]];
         for(char it:letter){
            solve(digits,idx+1,ans+it);
         }
       
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
    
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";

        solve(digits,0,"");
        return res;
    }
};