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
    void inorder(TreeNode* root, vector<int>& arr, int limit) {
        if (!root)
            return;
        if (limit == 0)
            return;
        inorder(root->left, arr, limit);
        arr.push_back(root->val);
        limit--;
        inorder(root->right, arr, limit);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        inorder(root, arr, k);
        return arr[k - 1];
    }
};