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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int& idx,
                    int start, int end) {
        if (start > end || idx<0) {
            return NULL;
        }
        int in_idx = mpp[postorder[idx]];
        TreeNode* newNode = new TreeNode(inorder[in_idx]);
        idx--;
        newNode->right = solve(inorder, postorder, idx, in_idx + 1, end);
        newNode->left = solve(inorder, postorder, idx, start, in_idx - 1);
        
        return newNode;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()) return NULL;
        for (int i = 0; i < inorder.size(); i++) {
            mpp[inorder[i]] = i;
        }
        int idx = inorder.size() - 1;
        return solve(inorder, postorder, idx, 0, inorder.size() - 1);
    }
};