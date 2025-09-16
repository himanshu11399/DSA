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
    unordered_map<int, int> mpp;
    bool ispresent = false;
    void inorder(TreeNode* root, int k) {
        if (root == NULL)
            return;
        inorder(root->left, k);
        int com = k - root->val;
        if (mpp.find(com) != mpp.end()) {
            ispresent = true;
            return;
        } else {
            mpp[root->val] = 1;
        }
        inorder(root->right,k);
    }
    bool findTarget(TreeNode* root, int k) {
        inorder(root, k);
        return ispresent;
    }
};