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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root)
            return ans;
        // Morris Traversal
        while (root) {
            // If left is not Exist
            if (!root->left) {
                ans.push_back(root->val);
                root = root->right;
            } else {
                // If left is exist;
                TreeNode* curr = root->left;
                while (curr->right && curr->right != root) {
                    curr = curr->right;
                }

                // If traversed First
                if (curr->right == root) {
                    ans.push_back(root->val);
                    curr->right = NULL;
                    root = root->right;
                } else {
                    curr->right = root;
                    root = root->left;
                }
            }
        }
        return ans;
    }
};