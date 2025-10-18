class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // step-1 to sort the both vector
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0;
        while (g.size() > i && s.size() > j) {
            if (s[j] >= g[i]) {
                i++;
            }
            j++;
        }
        return i;
    }
};