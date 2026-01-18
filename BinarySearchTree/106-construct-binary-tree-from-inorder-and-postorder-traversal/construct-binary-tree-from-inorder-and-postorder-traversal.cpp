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
    int search(vector<int>& inorder, int left, int right, int t) {
        for (int i = left; i <= right; i++) {
            if (inorder[i] == t)
                return i;
        }
        return -1;
    }

    TreeNode* build(vector<int>& inorder, vector<int>& postorder, int& PostIdx,
                    int left, int right) {
        if (left > right)
            return NULL;
        TreeNode* root = new TreeNode(postorder[PostIdx]);
        int idx = search(inorder, left, right, postorder[PostIdx]);
        PostIdx--;
        root->right = build(inorder, postorder, PostIdx, idx + 1, right);
        root->left = build(inorder, postorder, PostIdx, left, idx - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int PostIdx = postorder.size() - 1;
        return build(inorder, postorder, PostIdx, 0, inorder.size() - 1);
    }
};