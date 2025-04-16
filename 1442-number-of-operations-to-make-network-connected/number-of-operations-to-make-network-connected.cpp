class Solution {
public:
vector<int>parent;
vector<int>rank;

int find(int u){
    if(u==parent[u]){
        return u;
    }
    return parent[u]=find(parent[u]);
}

void Unionset(int u,int v){
    int pu=find(u);
    int pv=find(v);
    if(pu==pv){
        return;
    }
    if(rank[pu]>rank[pv]){
       parent[pv]=pu;
    }else if(rank[pv]>rank[pu]){
        parent[pu]=pv;
    }else{
        parent[pu]=pv;
    }
}


    int makeConnected(int n, vector<vector<int>>& connections) {

        if(connections.size()<n-1){
            return -1;
        }
      parent.resize(n);
      rank.resize(n,0);
      for(int i=0;i<n;i++){
        parent[i]=i;
      } 

      int node=n;  //it define the how many components

      for(auto vec:connections){
        if(find(vec[0])!=find(vec[1])){
            Unionset(vec[0],vec[1]);
            node--;
        }
      }
   return node-1;
    }
};