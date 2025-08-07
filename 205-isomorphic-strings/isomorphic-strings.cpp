class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<int,int>mpp;
        unordered_map<int,int>rev;
        string ans;

        for(int i=0;i<s.size();i++){

           if(mpp.find(s[i])!=mpp.end()){
            ans+=mpp[s[i]];
           }else{
            if(rev.find(t[i])!=rev.end()){
               return false; 
            }else{
                mpp[s[i]]=t[i];
                rev[t[i]]=s[i];
                ans+=t[i];
            }
           
           }
        }

        for(int i=0;i<s.size();i++){
           if(ans[i]!=t[i]){
            return false;
           }
        }
        return true;
    }
};