class Solution {
public:
    string longestNiceSubstring(string s) {
        if(s.size()<2) return "";

        unordered_set<char>uset;
        for(int i=0;i<s.size();i++){
            uset.insert(s[i]);
        }
        for(int i=0;i<s.size();i++){
            if(uset.count(tolower(s[i]))==true && uset.count(toupper(s[i]))==true) continue;

            string prev=longestNiceSubstring(s.substr(0,i));
            string next=longestNiceSubstring(s.substr(i+1));

            return prev.size()>=next.size()? prev:next;
        }
        return s;
    }
};