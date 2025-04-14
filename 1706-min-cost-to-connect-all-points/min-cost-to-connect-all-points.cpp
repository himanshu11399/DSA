class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int,int>>>adj(n);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1=points[i][0];
                int y1=points[i][1];

                int x2=points[j][0];
                int y2=points[j][1];

                int d=abs(x1-x2)+abs(y1-y2);
                adj[i].push_back({j,d});
                adj[j].push_back({i,d});

            }
        }
        //use the prims algorithum

       priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

       vector<bool>vis(n,false);
       pq.push({0,0});//wt,node
       int sum=0;

       while(!pq.empty()){
       int wt=pq.top().first;
       int node=pq.top().second;
       pq.pop();
        
        if(vis[node]==true)  continue;
        vis[node]=true;
        sum+=wt;
        for(auto it:adj[node]){
            int newnode=it.first;
            int dis=it.second;
            if(vis[newnode]==false){
                pq.push({dis,newnode});
            }
        }
       }return sum;
    }
};