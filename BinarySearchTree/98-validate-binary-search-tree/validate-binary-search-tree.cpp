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
    // st=maxleft,end=maxright
    bool helper(TreeNode* root, long st, long end) {
        if (root == NULL)
            return true;
        if (root->val <= st || root->val >= end)
            return false;
        return helper(root->left, st, root->val) &&
               helper(root->right, root->val, end);
    }
    bool isValidBST(TreeNode* root) { return helper(root, LONG_MIN, LONG_MAX); }
};