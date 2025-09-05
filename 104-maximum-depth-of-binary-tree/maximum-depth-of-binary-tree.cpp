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
    int maxDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
      queue<pair<TreeNode*,int>>q;
      q.push({root,1});
      int currentlevel=1;
      while(!q.empty()){
        auto [curr,level]=q.front();
        q.pop();
        if(level>currentlevel){
            currentlevel=level;
        }
        if(curr->left!=NULL){
            q.push({curr->left,level+1});
        }
        if(curr->right!=NULL){
            q.push({curr->right,level+1});
        }
      } 
      return currentlevel; 
    }
};