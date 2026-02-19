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
    bool isVerify(TreeNode* root, TreeNode*min, TreeNode*max) {
        if (!root)
            return true;
        if (min && root->val <= min->val)
            return false;
        if (max && root->val >= max->val)
            return false;
        return isVerify(root->left, min, root) &&
               isVerify(root->right, root, max);
    }
    bool isValidBST(TreeNode* root) {
        if (!root)
            return true;
        return isVerify(root,NULL,NULL);
    }
};