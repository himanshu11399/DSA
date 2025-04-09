class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
        }
         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
         pq.push({0,k});
         vector<int>result(n+1,1e9);
         result[k]=0;
         while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto &it:adj[node]){
                int adjnode=it.first;
                int wt=it.second;
                if(d+wt<result[adjnode]){
                    result[adjnode]=d+wt;
                    pq.push({d+wt,adjnode});
                }
            }
         }
         int maxans=0;
         for(int i=1;i<=n;i++){
            if(result[i]==1e9) return -1;
            maxans=max(maxans,result[i]);
         }return maxans;
    }
};