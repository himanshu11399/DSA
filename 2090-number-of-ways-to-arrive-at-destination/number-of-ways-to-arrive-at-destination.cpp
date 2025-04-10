class Solution {
public:
    int M = 1e9 + 7;

    int countPaths(int n, vector<vector<int>>& roads) {
        // Create adjacency list
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto& it : roads) {
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // Min heap: {dist, node}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<int> count(n, 0);

        dist[0] = 0;
        count[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [currDist, node] = pq.top();
            pq.pop();

            // Early stopping (optional optimization)
            if (currDist > dist[node]) continue;

            for (auto& [adjNode, weight] : adj[node]) {
                long long newDist = currDist + weight;

                if (newDist < dist[adjNode]) {
                    dist[adjNode] = newDist;
                    pq.push({newDist, adjNode});
                    count[adjNode] = count[node];
                } else if (newDist == dist[adjNode]) {
                    count[adjNode] = (count[adjNode] + count[node]) % M;
                }
            }
        }

        return count[n - 1];
    }
};
