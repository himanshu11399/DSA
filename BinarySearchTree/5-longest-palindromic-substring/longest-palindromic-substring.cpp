class Solution {
public:
  bool solve(string&s,int i,int j){
    if(i>j)return true;
    if(s[i]==s[j]){
        return solve(s,i+1,j-1);
    }
    return false;
  }
    string longestPalindrome(string s) {
        int n=s.size();
        
        int maxlen=1;
        string ans=s.substr(0,1);

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j) && maxlen<j-i+1){
                  maxlen=j-i+1;
                  ans=s.substr(i,j-i+1);
                }
            }
        }
        return ans;
    }
};