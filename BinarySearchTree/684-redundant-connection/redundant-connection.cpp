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

    bool unionset(int u, int v) {
        int uparent = find(u);
        int vparent = find(v);

        if (uparent == vparent) {
            return false;
        }

        if (rankvec[uparent] > rankvec[vparent]) {
            parent[vparent] = uparent;
        } else if (rankvec[vparent] > rankvec[uparent]) {
            parent[uparent] = vparent;
        } else {
            parent[uparent] = vparent;
            rankvec[vparent]++;
        }
        return true;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> ans;
        parent.resize(n + 1);
        rankvec.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        for (auto it : edges) {
            int u = it[0], v = it[1];
            if (!unionset(u, v)) {
                ans = {u, v};
            }
        }
        return ans;
    }
};