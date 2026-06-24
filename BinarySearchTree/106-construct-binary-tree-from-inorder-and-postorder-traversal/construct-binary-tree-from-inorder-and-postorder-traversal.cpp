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
    int idx;
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int idxi,
                    int idxj) {
        if (idxi > idxj) {
            return NULL;
        } else {
            idx--;
        }
        TreeNode* root = new TreeNode(postorder[idx]);
        int newIdx = mpp[postorder[idx]];
        root->right = solve(inorder, postorder, newIdx + 1, idxj);
        root->left = solve(inorder, postorder, idxi, newIdx - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        idx = postorder.size();
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }
        return solve(inorder, postorder, 0, inorder.size() - 1);
    }
};