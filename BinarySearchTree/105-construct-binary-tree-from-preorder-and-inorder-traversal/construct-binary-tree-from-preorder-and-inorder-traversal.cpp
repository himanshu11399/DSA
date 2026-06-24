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
    int idx=-1;
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,
                    int idxi, int idxj) {
        if (idxi > idxj) {
            return NULL;
        }else{
            idx++;
        }
        TreeNode* root = new TreeNode(preorder[idx]);
        int newIdx = mpp[preorder[idx]];
        root->left = solve(preorder, inorder, idxi, newIdx - 1);
        root->right = solve(preorder, inorder, newIdx + 1, idxj);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }
        return solve(preorder, inorder, 0, inorder.size() - 1);
    }
};