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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& idx,
                    int st, int en) {
        if (st > en)
            return NULL;
        int in_idx = mpp[preorder[idx]];
        TreeNode*newNode = new TreeNode(inorder[in_idx]);
        idx++;
        newNode->left = solve(preorder, inorder, idx, st, in_idx - 1);
        newNode->right = solve(preorder, inorder, idx, in_idx + 1, en);
        return newNode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }
        int idx=0;
        return solve(preorder, inorder, idx, 0, preorder.size() - 1);
    }
};