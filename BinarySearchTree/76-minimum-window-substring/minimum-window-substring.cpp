class Solution {
public:
    string minWindow(string s, string t) {
        int count=t.size();
        unordered_map<char,int>mpp;
        for(int i=0;i<count;i++){
            mpp[t[i]]++;
        }
        int i=0;
        int minans=INT_MAX;
        int start;

        for(int j=0;j<=s.size();j++){

            //Insert
            if(mpp.find(s[j])!=mpp.end()){
                if(mpp[s[j]]>0){
                    count--;
                }
            }
            mpp[s[j]]--;

            //Try to shrink the window  and Insert
            while(count==0){
                int len=j-i+1;
                if(minans>len){
                    minans=len;
                    start=i;
                }
                mpp[s[i]]++;
                if(mpp[s[i]]>0){
                  count++;
                }
                i++;
            }
        }

        string ans="";
        if(minans!=INT_MAX){
            ans=s.substr(start,minans);
        }
        return ans;
    }
};