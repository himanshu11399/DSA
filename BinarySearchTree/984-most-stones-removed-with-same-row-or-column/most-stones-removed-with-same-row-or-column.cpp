class Solution {
public:
    vector<int> parent;
    vector<int> rankvec;

    int find(int n) {
        if (parent[n] == n) {
            return n;
        }
        return parent[n] = find(parent[n]);
    }

    void unionset(int a, int b) {
        int aparent = find(a);
        int bparent = find(b);

        if (aparent == bparent) {
            return;
        }
        if (rankvec[aparent] > rankvec[bparent]) {
            parent[bparent] = aparent;
        } else if (rankvec[bparent] > rankvec[aparent]) {
            parent[aparent] = bparent;
        } else {
            parent[aparent] = bparent;
            rankvec[bparent]++;
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        parent.resize(n);
        rankvec.resize(n,0);

        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    unionset(i,j);
                }
            }
        }

        int groups=0;
        for(int i=0;i<n;i++){
            if(parent[i]==i){
                groups++;
            }
        }
      return n-groups;

    }
};