class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    bool unionByRank(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) {
            return false;
        }
        if (rank[px] > rank[py]) {
            parent[py] = px;
        } else if (rank[py] > rank[px]) {
            parent[px] = py;
        } else {
            parent[px] = py;
            rank[py]++;
        }
        return true;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int count = 0;

        for (int i = n-1; i >= 1; i--) {
            int node = i;
            int x = stones[i][0];
            int y = stones[i][1];

            for (int j = i - 1; j >= 0; j--) {
                int a = stones[j][0];
                int b = stones[j][1];

                if (x == a || y == b) {
                    if (unionByRank(node, j)) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};