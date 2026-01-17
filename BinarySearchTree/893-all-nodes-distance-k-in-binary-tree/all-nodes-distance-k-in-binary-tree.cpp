/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        if (!root)
            return res;

        // parent,child
        map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;

        // parent map
        q.push(root);
        parent[root] = NULL;

        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if (curr->left) {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right) {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }

        // Target
        unordered_set<TreeNode*> visited;
        queue<TreeNode*> bfs;
        bfs.push(target);
        visited.insert(target);
        int dist = 0;

        while (!bfs.empty()) {
            int n = bfs.size();

            if (dist == k)
                break;

            for (int i = 0; i < n; i++) {
                TreeNode* curr = bfs.front();
                bfs.pop();

                if (curr->left && !visited.count(curr->left)) {
                    visited.insert(curr->left);
                    bfs.push(curr->left);
                }
                if (curr->right && !visited.count(curr->right)) {
                    visited.insert(curr->right);
                    bfs.push(curr->right);
                }
                if (parent.find(curr) != parent.end() &&
                    !visited.count(parent[curr])) {
                    if (parent[curr] != NULL) {
                        visited.insert(parent[curr]);
                        bfs.push(parent[curr]);
                    }
                }
            }
            dist++;
        }

        while (!bfs.empty()) {
            TreeNode* curr = bfs.front();
            bfs.pop();
            res.push_back(curr->val);
        }
        return res;
    }
};