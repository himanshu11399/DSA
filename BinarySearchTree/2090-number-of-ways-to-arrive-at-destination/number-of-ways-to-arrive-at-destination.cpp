class Solution {
public:
    int M = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int, long long>>> adj(n);
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<long long> dis(n, LLONG_MAX);
        vector<int> ways(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;

        pq.push({0, 0});
        dis[0] = 0;
        ways[0] = 1;

        while (!pq.empty()) {
            auto i = pq.top();
            long long cost = i.first;
            int node = i.second;
            pq.pop();

            for (auto it : adj[node]) {
                int adjnode = it.first;
                long long wt = it.second;
                if (cost + wt < dis[adjnode]) {
                    pq.push({cost + wt, adjnode});
                    dis[adjnode] = cost + wt;
                    ways[adjnode] = ways[node];
                } else if (cost + wt == dis[adjnode]) {
                    ways[adjnode] = (ways[adjnode] + ways[node]) % M;
                }
            }
        }

        return ways[n - 1] % M;
    }
};