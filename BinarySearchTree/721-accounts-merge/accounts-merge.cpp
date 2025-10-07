class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int n) {
        if (parent[n] == n) {
            return n;
        }
        return parent[n] = find(parent[n]);
    }
    void unionset(int x, int y) {
        int xparent = find(x);
        int yparent = find(y);

        if (xparent == yparent)
            return;

        if (rank[xparent] > rank[yparent]) {
            parent[yparent] = xparent;
        } else if (rank[yparent] > rank[xparent]) {
            parent[xparent] = yparent;
        } else {
            parent[xparent] = yparent;
            rank[yparent]++;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        // step-1 union of all the same accounts

        // email->index
        unordered_map<string, int> mailmap;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                // if they find the same email in the set so perform union
                if (mailmap.find(email) != mailmap.end()) {
                    unionset(i, mailmap[email]);
                } else {
                    mailmap[email] = i;
                }
            }
        }

        // step-2 merge all the same emails in a mapp for the further sort
        //  index->[emails]
        unordered_map<int, set<string>> mergemap;

        for (auto it : mailmap) {
            string mail = it.first;
            int accountidx = it.second;
            int parentidx = find(accountidx);
            mergemap[parentidx].insert(mail);
        }

        //Final step to prepare the answer

        vector<vector<string>>ans;
        for(auto it:mergemap){
            int index=it.first;
            vector<string>temp;
            temp.push_back(accounts[index][0]);
            temp.insert(temp.end(),it.second.begin(),it.second.end());
            ans.push_back(temp);
        }
        return ans;
    }
};