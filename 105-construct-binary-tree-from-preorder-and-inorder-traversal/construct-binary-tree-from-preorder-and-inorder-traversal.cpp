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
    int search(vector<int> arr, int st, int end, int val) {
        for (int i = st; i <= end; i++) {
            if (arr[i] == val) {
                return i;
            }
        }
        return -1;
    }
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int left,
                     int right, int& preIdx) {

        if (left > right)
            return NULL;

        TreeNode* newNode = new TreeNode(preorder[preIdx]);

        int inIdx=search(inorder,left,right,preorder[preIdx]);
        preIdx++;

        newNode->left = helper(preorder, inorder, left, inIdx - 1, preIdx);
        newNode->right =helper(preorder, inorder, inIdx + 1, right, preIdx);

        return newNode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        return helper(preorder, inorder, 0, inorder.size()-1, idx);
    }
};