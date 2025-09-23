class Solution {
public:
    int n, m;
    vector<vector<int>> direction{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    bool solve(vector<vector<char>>& board, int i, int j, int idx, string& word) {
        if (idx == word.size()) return true;
        if (i < 0 || j < 0 || i >= m || j >= n) return false;
        if (board[i][j] != word[idx]) return false;

        char temp = board[i][j];
        board[i][j] = '$';  // mark visited

        for (auto& it : direction) {
            if (solve(board, i + it[0], j + it[1], idx + 1, word)) {
                board[i][j] = temp;  // restore before returning
                return true;
            }
        }

        board[i][j] = temp;  // restore back
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (solve(board, i, j, 0, word)) return true;
                }
            }
        }
        return false;
    }
};
