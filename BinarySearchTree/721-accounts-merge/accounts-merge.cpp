class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x) {
        if (parent[x] == x) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    bool unionByRank(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return false;

        if (rank[px] > rank[py]) {
            parent[py] = px;
        } else if (rank[py] > rank[px]) {
            parent[px] = py;
        } else {
            parent[px] = py;
            rank[py]++;
        }
        return true;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        vector<vector<string>> ans;

        unordered_map<string, int> mpp;

        // store ans to remove duplicate emails
        unordered_map<int, set<string>> bucket;

        // Union Account
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                if (mpp.find(accounts[i][j]) != mpp.end()) {
                    string email = accounts[i][j];
                    if (mpp.find(email) != mpp.end()) {
                        unionByRank(i, mpp[email]);
                    }
                } else {
                    mpp[accounts[i][j]] = i;
                }
            }
        }

        // insert emails into bucket
        for (auto it : mpp) {
            string email = it.first;
            int idx = it.second;

            int root = find(idx);
            bucket[root].insert(email);
        }

        for (auto it : bucket) {
            int root = it.first;
            vector<string>temp;

            temp.push_back(accounts[root][0]);

            for (auto email : it.second) {
                temp.push_back(email);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};