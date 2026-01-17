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
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int total = 0;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* it = q.front();
            q.pop();
            total += 1;
            if (it->left)
                q.push(it->left);
            if (it->right)
                q.push(it->right);
        }
        return total;
    }
};