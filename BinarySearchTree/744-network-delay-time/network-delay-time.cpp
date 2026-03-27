class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        vector < vector<pair<int, int>>> adj(n+1);
        for (auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        vector<int> dist(n+1,1e9);

        pq.push({0, src});
        dist[src] = 0;

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int wt = it.first;
            int node = it.second;

            for (auto i : adj[node]) {
                int adjNode = i.first;
                int dis = i.second;

                if (dist[adjNode] > wt + dis) {
                    pq.push({wt + dis, adjNode});
                    dist[adjNode] = wt + dis;
                }
            }
        }

        int maxans = INT_MIN;
        for (int i = 1; i < n+1; i++) {
            maxans = max(maxans, dist[i]);
        }

        return maxans==1e9?-1:maxans;
    }
};