class Solution {
public:
    int maxDepth(string s) {
        int index=0;
        int m=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                index++;
                m=max(m,index);
            }else if(s[i]==')'){
                index--; 
            }
        }
        return m;
    }
};