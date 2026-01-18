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
    int search(vector<int>inorder,int left,int right,int t){
        int idx;
        for(int i=left;i<right;i++){
            if(inorder[i]==t){
                idx=i;
                break;
            }
        }
        return idx;
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& PreIdx,
                    int left, int right) {
        if (left > right)
            return NULL;
        TreeNode* root = new TreeNode(preorder[PreIdx]);
        int idx = search(inorder, left, right, preorder[PreIdx]);
        PreIdx++;
        root->left = build(preorder, inorder, PreIdx, left, idx - 1);
        root->right = build(preorder, inorder, PreIdx, idx + 1, right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int PreIdx = 0;
        return build(preorder, inorder, PreIdx, 0, inorder.size() - 1);
    }
};