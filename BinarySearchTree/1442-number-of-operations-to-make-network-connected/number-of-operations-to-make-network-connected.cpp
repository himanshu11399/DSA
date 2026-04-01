class Solution {
public:
    int find(vector<int>& parent, int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent, parent[x]);
    }

    bool UnionByRank(vector<int>& parent, vector<int>& rank, int x, int y) {
        int px = find(parent, x);
        int py = find(parent, y);

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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int reqEdges = n - 1;
        int edges = connections.size();
        if (reqEdges > edges) {
            return -1;
        }

        vector<int> parent(n);
        vector<int> rank(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int count=n-1;
        for(auto it:connections){
            if(UnionByRank(parent,rank,it[0],it[1])){
              count--;
            }
        }
        return count;
    }
};