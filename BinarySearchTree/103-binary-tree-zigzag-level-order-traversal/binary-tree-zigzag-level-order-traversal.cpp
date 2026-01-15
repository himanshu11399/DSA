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
    vector<vector<int>> ans;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool left = true;

        while (!q.empty()) {
            int n = q.size();

            vector<int> res;
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                res.push_back(node->val);
                if (node->left != NULL) {
                    q.push(node->left);
                }
                if (node->right != NULL) {
                    q.push(node->right);
                }
            }

            if (left) {
                left = false;
            } else {
                reverse(res.begin(), res.end());
                left = true;
            }

            ans.push_back(res);
        }

        return ans;
    }
};