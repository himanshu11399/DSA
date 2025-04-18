class Solution {
public:
    vector<int>parent;
    vector<int>rank;

    int find(int v){
        if(v==parent[v]) return v;
        return parent[v]=find(parent[v]);
    }

    void unionset(int v,int u){
        int pu=find(u);
        int pv=find(v);
        if(pu==pv) return;
        if(rank[pu]>rank[pv]){
            parent[pv]=pu;
        }else if(rank[pv]>rank[pu]){
            parent[pu]=pv;
        }else{
            parent[pu]=pv;
            rank[pv]++;
        }
    }
        
        vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        parent.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        //Step-1
        unordered_map<string,int>mapmail;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail=accounts[i][j];
                if(mapmail.find(mail)==mapmail.end()){
                    mapmail[mail]=i;
                }else{
                    unionset(i,mapmail[mail]);
                }
            }
        }

        //step-2
          vector<vector<string>> merge(n);
        for(auto it:mapmail){
            string mail=it.first;
            int node=find(it.second);
            merge[node].push_back(mail);
        }

        //steop-3
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(merge[i].empty()) continue;
            sort(merge[i].begin(),merge[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:merge[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        
        
return ans;
    }
};