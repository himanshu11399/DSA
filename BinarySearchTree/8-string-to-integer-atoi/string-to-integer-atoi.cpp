class Solution {
public:
void atoi(string s, int& i, long long& ans) {
        if (s.size() <= i || !isdigit(s[i])) {
            return;
        }
        ans=ans*10+(s[i]-'0');
        if(ans>(long long)INT_MAX+1) return;

        i++;
        atoi(s, i, ans);
    }
    int myAtoi(string s) {
        int idx = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                idx++;
            } else {
                break;
            }
        }
        int sign = 1;
        if (s[idx] == '-' ){
            sign = -1;
            idx++;
        } else if (s[idx] == '+') {
          idx++;
        }
        long long ans=0;
        atoi(s,idx,ans);
        ans*=sign;
        if(ans>INT_MAX) return INT_MAX;
        if(ans<INT_MIN) return INT_MIN;

        return (int)ans;
    }
};