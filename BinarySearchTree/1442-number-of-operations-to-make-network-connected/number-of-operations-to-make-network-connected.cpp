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

    bool unionset(int x, int y) {

        int xparent = find(x);
        int yparent = find(y);

        if (xparent == yparent) {
            return false;
        }

        if (rankvec[xparent] > rankvec[yparent]) {
            parent[yparent] = xparent;
        } else if (rankvec[yparent] > rankvec[xparent]) {
            parent[xparent] = yparent;
        } else {
            parent[xparent] = yparent;
            yparent++;
        }
        return true;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1)
            return -1;

        parent.resize(n);
        rankvec.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int count = n-1;
        for (auto it : connections) {
            if (unionset(it[0], it[1])) {
                count--;
            }
        }
        return count;
    }
};