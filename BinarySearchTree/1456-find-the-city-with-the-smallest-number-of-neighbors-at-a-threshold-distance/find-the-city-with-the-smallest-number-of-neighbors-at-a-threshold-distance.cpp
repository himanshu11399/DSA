class Solution {
public:
    void floyd(int n, vector<vector<int>>& dist) {
        // for via
        for (int via = 0; via < n; via++) {
            // for row
            for (int i = 0; i < n; i++) {
                // for col
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector < int > (n, 1e9));
        for (auto it : edges) {
            int u = it[0], v = it[1], wt = it[2];
            dist[u][v] = wt;
            dist[v][u] = wt;
        }

        floyd(n, dist);

        int minReachable = n + 1;
        int resultcity = 0;

        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            if (count <= minReachable) {
                minReachable = count;
                resultcity = i;
            }
        }
        return resultcity;
    }
};