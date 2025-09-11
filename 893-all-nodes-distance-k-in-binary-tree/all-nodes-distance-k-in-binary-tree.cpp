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
    unordered_map<TreeNode*, TreeNode*> parent;
    // map<root,parentroot>
    void inorder(TreeNode* root) {
        if (root == NULL)
            return;
        if (root->left) {
            parent[root->left] = root;
            inorder(root->left);
        }
        if (root->right) {
            parent[root->right] = root;
            inorder(root->right);
        }
    }

    void BFS(TreeNode* target, int k, vector<int>& ans) {
        queue<TreeNode*> q;
        q.push(target);

        unordered_set<int> visited;
        visited.insert(target->val);

        while (!q.empty()) {
            int n = q.size();
            if (k == 0) {
                break;
            } else {
                while (n--) {
                    TreeNode* curr = q.front();
                    q.pop();

                    // left
                    if (curr->left != NULL && !visited.count(curr->left->val)) {
                        q.push(curr->left);
                        visited.insert(curr->left->val);
                    }

                    // right
                    if (curr->right != NULL && !visited.count(curr->right->val)) {
                        q.push(curr->right);
                        visited.insert(curr->right->val);
                    }

                    // parent
                    if (parent.count(curr) && !visited.count(parent[curr]->val)) {
                        q.push(parent[curr]);
                        visited.insert(parent[curr]->val);
                    }
                }
                k--;
            }
        }
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();
            ans.push_back(temp->val);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        if (root == NULL)
            return ans;

        inorder(root);
        BFS(target, k, ans);
        return ans;
    }
};