class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    matrix[i][j] = matrix[i][j] +
                                   min(matrix[i + 1][j], matrix[i + 1][j + 1]);
                } else if (j == n - 1) {
                    matrix[i][j] = matrix[i][j] +
                                   min(matrix[i + 1][j], matrix[i + 1][j - 1]);
                } else {
                    int rightmin = min(matrix[i + 1][j], matrix[i + 1][j + 1]);
                    matrix[i][j] =
                        matrix[i][j] + min(matrix[i + 1][j - 1], rightmin);
                }
            }
        }
        int ans = 1e9;
        for (int i = 0; i < n; i++) {
            ans = min(ans, matrix[0][i]);
        }
        return ans;
    }
};