class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        stack<pair<int, int>> st;
        int n = matrix.size();
        int m = matrix[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    st.push({i, j});
                }
            }
        }

        while(!st.empty()){
            auto [row,col]=st.top();
            st.pop();

            //For Row
            for(int i=0;i<m;i++){
                matrix[row][i]=0;
            }

            //for col
            for(int i=0;i<n;i++){
                matrix[i][col]=0;
            }
        }
    }
};