class Solution {
public:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    void dfs(vector<vector<char>>& board, int sr, int sc,
             vector<vector<bool>>& vis) {
        vis[sr][sc] = true;
        for (auto it : dir) {
            int nrow = sr + it[0];
            int ncol = sc + it[1];
            if (nrow >= 0 && nrow < board.size() && ncol >= 0 &&
                ncol < board[0].size() - 1 && !vis[nrow][ncol] &&
                board[nrow][ncol] == 'O') {
                dfs(board, nrow, ncol, vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int, int>> q;
        vector<vector<bool>> vis(n + 1, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    if (board[i][j] == 'O') {
                        q.push({i, j});
                    }
                }
            }
        }

        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            dfs(board, row, col, vis);
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && vis[i][j] == false) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};