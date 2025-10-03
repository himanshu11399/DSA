class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        vector<vector<pair<int, int>>> adj(n + 1);
        //{v,wt}
        for (auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>pq;
        pq.push({0, src});
        //{dis,src}
        vector<int> dist(n + 1, 1e9);
        dist[src] = 0;
        while (!pq.empty()) {
            auto it = pq.top();
            int cost = it.first;
            int node = it.second;
            pq.pop();
            for (auto i : adj[node]) {
                int adjnode = i.first;
                int wt = i.second;
                if (cost + wt < dist[adjnode]) {
                    pq.push({cost + wt, adjnode});
                    dist[adjnode] = cost + wt;
                }
            }
        }
        int maxdelay = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9) {
                return -1;
            }
            maxdelay = max(maxdelay, dist[i]);
        }
        return maxdelay;
    }
};