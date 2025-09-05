/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int maxd(TreeNode*root){
    if(root==NULL){
        return 0;
    }
    int left=maxd(root->left);
    int right=maxd(root->right);
    return max(left,right)+1;
}
    bool isBalanced(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        int left=maxd(root->left);
        int right=maxd(root->right);
        int diff=abs(left-right);
        if(diff>1){
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
};