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
bool isValid(TreeNode*root,long long leftmax,long long rightmax){
    if(!root){
        return true;
    }
    if(root->val <= leftmax || root->val >= rightmax){
        return false;
    }
   return isValid(root->left,leftmax,root->val) && isValid(root->right,root->val,rightmax);
}
    bool isValidBST(TreeNode* root) {
      return isValid(root,LLONG_MIN,LLONG_MAX);  
    }
};