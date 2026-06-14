class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> dir = {{-1, 0},  {1, 0}, {0, -1}, {0, 1},
                                   {-1, -1}, {1, 1}, {1, -1}, {-1, 1}};
        vector<pair<int, pair<int, int>>> change;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // find Live Nodes
                int LiveNeighbours = 0;
                for (auto it : dir) {
                    int row = i + it[0];
                    int col = j + it[1];

                    if (row>=0 && row<n && col>=0 && col<m) {
                        if (board[row][col] == 1) {
                            LiveNeighbours++;
                        }
                    }
                }

                if (board[i][j] == 1) {
                    if (LiveNeighbours < 2 || LiveNeighbours > 3) {
                        change.push_back({0, {i, j}});
                    }
                } else {
                    if (LiveNeighbours == 3) {
                        change.push_back({1, {i, j}});
                    }
                }
            }
        }

        // Reflect changes
        for (auto it : change) {
            int val = it.first;
            int row = it.second.first;
            int col = it.second.second;

            board[row][col] = val;
        }
    }
};