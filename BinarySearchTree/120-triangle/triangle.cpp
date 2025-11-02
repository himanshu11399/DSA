class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int>t(n);
        for(int i=0;i<=n-1;i++){
            t[i]=triangle[n-1][i];
        }
        for (int row = n - 2; row >= 0; row--) {
            for (int col = 0; col <= row; col++) {
                t[col]=triangle[row][col]+min(t[col],t[col+1]);
            }
        }
        return t[0];
    }
};