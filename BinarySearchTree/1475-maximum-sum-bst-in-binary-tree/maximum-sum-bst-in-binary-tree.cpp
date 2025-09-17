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
     class Info{
       public:
       int max;
       int min;
       int size;
       bool isBST;
       
       Info(int mi,int mx,int sz,bool bst){
           min=mi;
           max=mx;
           size=sz;
           isBST=bst;
       }
   };

   int ans=0;
   
   Info helper(TreeNode*root){
       if(root==NULL){
           return Info(INT_MAX,INT_MIN,0,true);
       }
       Info left=helper(root->left);
       Info right=helper(root->right);
       
       if(left.isBST && right.isBST && root->val > left.max && root->val < right.min){
           int currmin=min(root->val,left.min);
           int currmax=max(root->val,right.max);
           int currsize=left.size+right.size+root->val;
           ans=max(ans,currsize);

           return Info(currmin,currmax,currsize,true);
       }else{
           return Info(INT_MIN,INT_MAX,max(left.size,right.size),false);
       }
   }
    int maxSumBST(TreeNode* root) {
        helper(root);
        return ans;
    }
};