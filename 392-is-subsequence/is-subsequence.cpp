class Solution {
public:
    bool isSubsequence(string s, string t) {
       int left=0,right=0;

       while(right<t.size()){
         if(left<s.size() && s[left]==t[right]){
            left++;
            right++;
         }else{
            right++;
         }
       }
       if(left!=s.size()) return false;
       return true;
    }
};