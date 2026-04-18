class Solution {
public:
vector<vector<int>>dp;
    int solve(string&s1,string&s2,int i,int j){
     if(i>=s1.size() || j>=s2.size()){
        return 0;
     }
     if(dp[i][j]!=-1){
        return dp[i][j];
     }
     if(s1[i]==s2[j]){
        return solve(s1,s2,i+1,j+1)+1;
     }

     int left=solve(s1,s2,i+1,j);
     int right=solve(s1,s2,i,j+1);

     return dp[i][j]=max(left,right);
    }
    int longestCommonSubsequence(string text1, string text2) {
      int n=text1.size();
      int m=text2.size();
      dp.assign(n+1,vector<int>(m+1,-1));
      return solve(text1,text2,0,0);  
    }
};