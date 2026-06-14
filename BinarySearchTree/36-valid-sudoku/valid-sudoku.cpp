class Solution {
public:
    bool validate(vector<vector<char>>& board, int sr, int sc, int er, int ec) {
        unordered_set<char> st;
        for (int i = sr; i <= er; i++) {
            for (int j = sc; j <= ec; j++) {
                if (board[i][j] == '.')
                    continue;
                if (st.count(board[i][j])) {
                    return false;
                }
                st.insert(board[i][j]);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        // Validate Row
        for (int row = 0; row < 9; row++) {
            unordered_set<char> st;
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.')
                    continue;
                if (st.count(board[row][col])) {
                    return false;
                }
                st.insert(board[row][col]);
            }
        }

        // Validate col
        for (int col = 0; col < 9; col++) {
            unordered_set<char> st;
            for (int row = 0; row < 9; row++) {
                if (board[row][col] == '.')
                    continue;
                if (st.count(board[row][col])) {
                    return false;
                }
                st.insert(board[row][col]);
            }
        }

        // Validate Boxes
        for (int sr = 0; sr < 9; sr += 3) {
            int er = sr + 2;
            for (int sc = 0; sc < 9; sc += 3) {
                int ec = sc + 2;
                if (!validate(board, sr, sc, er, ec)) {
                    return false;
                }
            }
        }
        return true;
    }
};