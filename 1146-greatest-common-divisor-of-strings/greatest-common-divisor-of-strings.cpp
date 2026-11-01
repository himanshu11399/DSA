class Solution {
public:
    int gcd(int a, int b) {
        int rem = a % b;
        if (rem == 0) {
            return b;
        }
        return gcd(b, rem);
    }
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2!=str2+str1){
            return "";
        }

        int idx=gcd(str1.size(),str2.size());
        return str1.substr(0,idx);
    }
};