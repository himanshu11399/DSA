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
    int kthSmallest(TreeNode* root, int k) {
        if(root==NULL) return NULL;

        TreeNode*curr=root;
        int count=0;
        int value=0;
        while(curr!=NULL){
            if(count==k){
              return value;  
            }
            if(curr->left==NULL){
                value=curr->val;
                count++;
                curr=curr->right;
            }else{
                TreeNode*leftnode=curr->left;
                while(leftnode->right!=NULL){
                    leftnode=leftnode->right;
                }
                leftnode->right=curr;
                TreeNode*temp=curr;
                curr=curr->left;
                temp->left=NULL;
            }
        }return value;
    }
};