class Solution {
public:
    vector<string> ans;
    void bfs(int n, int pos, string& curr, char prev) {
        if (n == pos) {
            ans.push_back(curr);
            return;
        }

        if (prev != '0' || pos==0) {
            curr.push_back('0');
            bfs(n, pos + 1, curr, '0');
            curr.pop_back();
        }

        curr.push_back('1');
        bfs(n, pos + 1, curr, '1');
        curr.pop_back();
    }
    vector<string> validStrings(int n) {
        string s = "";
        bfs(n, 0, s, '0');
        return ans;
    }
};