class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        int idx=0;
        while(idx<n && n-idx>citations[idx]){
            idx++;
        }
        return n-idx;
    }
};