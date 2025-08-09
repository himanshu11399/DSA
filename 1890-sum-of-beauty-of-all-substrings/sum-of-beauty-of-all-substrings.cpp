class Solution {
public:
    int beauty(string& s, int i, int j) {
        int minel = INT_MAX;
        int maxel = INT_MIN;
        vector<int>freq(26,0);

        for(int ele=i;ele<=j;ele++){
            freq[s[ele]-'a']++;
        }

        for(int f:freq){
            if(f>0){
                minel=min(minel,f);
                maxel=max(maxel,f);
            }
        }
        return maxel - minel;
    }
    int beautySum(string s) {
        int count = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                count += beauty(s, i, j);
            }
        }
        return count;
    }
};