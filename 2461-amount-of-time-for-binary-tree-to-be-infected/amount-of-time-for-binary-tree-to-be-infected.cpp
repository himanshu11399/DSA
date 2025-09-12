/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;
    TreeNode* find = NULL;

    void addparent(TreeNode* root, int start) {
        if (root == NULL)
            return;
        if (root->left != NULL) {
            parent[root->left] = root;
            addparent(root->left,start);
        }
        if (root->val == start) {
            find = root;
        }
        if (root->right) {
            parent[root->right] = root;
            addparent(root->right,start);
        }
    }

    void BFS(int& time) {
        queue<TreeNode*> q;
        q.push(find);
        unordered_set<int> visited;
        visited.insert(find->val);

        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                TreeNode* curr = q.front();
                q.pop();

                if (curr->left != NULL && !visited.count(curr->left->val)) {
                    q.push(curr->left);
                    visited.insert(curr->left->val);
                }

                if (curr->right != NULL && !visited.count(curr->right->val)) {
                    q.push(curr->right);
                    visited.insert(curr->right->val);
                }

                if (parent.find(curr) != parent.end() &&
                    !visited.count(parent[curr]->val)) {
                    q.push(parent[curr]);
                    visited.insert(parent[curr]->val);
                }
            }
            time++;
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        if (root == NULL)
            return 0;
        int time = 0;
        addparent(root, start);
        BFS(time);
        return time-1;
    }
};