class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {

        vector<vector<pair<int, int>>> adj(n);
        for (auto it : flights) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
        }

        queue<vector<int>> pq;
        vector<int> dist(n, INT_MAX);

        pq.push({0, src, 0});
        dist[src] = 0;

        while (!pq.empty()) {
            auto it = pq.front();
            pq.pop();

            int price = it[0];
            int u = it[1];
            int stops = it[2];

            if(stops > k) {
                continue;
            }

            for (auto i : adj[u]) {
                int v = i.first;
                int wt = i.second;

                if (dist[v] > wt + price) {
                    pq.push({wt + price, v, stops + 1});
                    dist[v] = wt + price;
                }
            }
        }

        if(dist[dst]==INT_MAX){
            return -1;
        }

        return dist[dst];
    }
};