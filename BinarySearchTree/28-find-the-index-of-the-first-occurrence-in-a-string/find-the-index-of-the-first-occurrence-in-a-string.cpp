class Solution {
public:
    int strStr(string haystack, string needle) {
        int idx = 0;
        for (int i = 0; i < haystack.size(); i++) {
            if (haystack[i] == needle[idx]) {
                int stidx = i;
                while ((i < haystack.size() && idx<needle.size()) && haystack[i] == needle[idx]) {
                    if (idx >= needle.size()) {
                        break;
                    }
                    idx++;
                    i++;
                }
                if (idx >= needle.size()) {
                    return stidx;
                } else {
                    idx=0;
                    i=stidx;
                }
            }
        }
        return -1;
    }
};