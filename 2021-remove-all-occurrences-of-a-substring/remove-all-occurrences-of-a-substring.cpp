class Solution {
public:
    string removeOccurrences(string s, string part) {
       while(s.size()>=0){
        int start=-1;
         if(s.find(part)<s.size()){
           start=s.find(part);
           s.erase(start,part.size());
         }else{
            break;
         }
       }
       return s; 
    }
};