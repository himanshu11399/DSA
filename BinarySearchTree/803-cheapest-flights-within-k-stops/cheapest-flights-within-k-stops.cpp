class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        queue<pair<int,pair<int,int>>>q;

        q.push({0,{src,0}});
        vector<int>dist(n,1e9);
        dist[src]=0;

        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int stop=it.first;
            int node=it.second.first;
            int dis=it.second.second;

            if(stop>k) continue;

            for(auto i:adj[node]){
                int adjnode=i.first;
                int wt=i.second;
                
               if(dis+wt<dist[adjnode]){
                dist[adjnode]=dis+wt;
                q.push({stop+1,{adjnode,dis+wt}});
               }
            }
        }
        if(dist[dst]==1e9){
            return -1;
        }return dist[dst];
    }
};