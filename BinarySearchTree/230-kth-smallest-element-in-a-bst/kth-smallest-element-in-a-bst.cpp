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
    int ans = -1;
    int limit;
    void inorder(TreeNode* root) {
        if (!root) {
            return;
        }
        inorder(root->left);
        if (limit == 0 && ans==-1) {
            ans = root->val;
        } else {
            limit--;
        }
        inorder(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        limit=k-1;
        inorder(root);
        return ans;
    }
};