class Solution {
public:
    int compress(vector<char>& chars) {

        int idx=0;
        for(int i=0;i<chars.size();i++){
            char ch=chars[i];
            int count=0;
            while(i<chars.size() && chars[i]==ch){
                count++;
                i++;
            }
            if(count==1){
             chars[idx++]=ch;
            }else{
              chars[idx++]=ch;
              string str=to_string(count);
              for(char st:str){
                chars[idx++]=st;
              }  
            }
            i--;
        }
      chars.resize(idx);
        return idx;
    }
};