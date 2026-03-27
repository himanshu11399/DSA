class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long mod = 1e9 + 7;

        vector<vector<pair<long long, long long>>> adj(n);
        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>,
                       greater<pair<long long, long long>>>
            pq;
        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;

        while (!pq.empty()) {
            auto [wt, node] = pq.top();
            pq.pop();

            for (auto it : adj[node]) {
                int adjNode = it.first;
                long long dis = wt+it.second;

                if (dist[adjNode] > dis) {
                    ways[adjNode]=ways[node];
                    pq.push({dis, adjNode});
                    dist[adjNode] = dis;
                }else if(dist[adjNode]==dis){
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }
            }
        }

        // int minCost = dist[n-1];
       int maxWays = ways[n-1]%mod;
        return maxWays;
    }
};