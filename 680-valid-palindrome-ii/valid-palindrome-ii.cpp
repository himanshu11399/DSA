class Solution {
public:

    bool ischeck(string&s,int i,int j){
        if(i>=j) return true;
        if(s[i]!=s[j]) return false;
        return ischeck(s,i+1,j-1);
    }
    bool validPalindrome(string s) {
        int left=0;
        int right=s.size()-1;

        while(left<=right){
          if(s[left]!=s[right]){
           return ischeck(s,left+1,right) || ischeck(s,left,right-1);
          }else{
            left++;
            right--;
          }
        }
        return true;
    }
};