class Solution {
public:
    vector<vector<int>> dp;
    bool solve(int i, int j, string& s1, string& s2) {
        if(i<0 && j<0) return true;
        if(i>=0 && j<0) return false;
        if(i<0 && j>=0){
            for(int k=0;k<=j;k++){
                if(s2[k]!='*'){
                    return false;
                }
            }
            return true;
        }

        if(dp[i][j]!=-1) return dp[i][j];

        if(s1[i]==s2[j] || s2[j]=='?'){
            return dp[i][j]= solve(i-1,j-1,s1,s2);
        }else if(s2[j]=='*'){
            return dp[i][j]= (solve(i-1,j,s1,s2) || solve(i,j-1,s1,s2));
        }else{
            return dp[i][j]= false;
        }


    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        dp.assign(n + 1, vector<int>(m + 1, -1));
        return solve(n - 1, m - 1, s, p);
    }
};