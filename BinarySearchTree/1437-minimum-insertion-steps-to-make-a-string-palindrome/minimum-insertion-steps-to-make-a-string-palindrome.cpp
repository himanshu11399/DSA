class Solution {
public:
vector<vector<int>>dp;
    int solve(string& str,int i,int j){
        if(j<0 || i>j || i==j) return 0;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(str[i]==str[j]){
            return dp[i][j]=solve(str,i+1,j-1);
        }
        int left=solve(str,i+1,j)+1;
        int right=solve(str,i,j-1)+1;
        return dp[i][j]=min(left,right);
    }
    int minInsertions(string str) {
       int n=str.size();
       dp.assign(n+1,vector<int>(n+1,-1));
       return solve(str,0,n-1);
    }
};