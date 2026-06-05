class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int n=citations.size();
        int idx=0;
        while(idx<n && citations[idx]<n-idx){
             idx++;
        }return n-idx;
    }
};
