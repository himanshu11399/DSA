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
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int>result;
        TreeNode*curr=root;
        while(curr!=NULL){
              result.push_back(curr->val);

            if(curr->left==NULL){
                
                curr=curr->right;
            }else{
                TreeNode*leftnode=curr->left;

                while(leftnode->right!=NULL){
                    leftnode=leftnode->right;
                }

                leftnode->right=curr->right;
                curr->right=NULL;
                curr=curr->left;
            }
        }
        return result;
    }
};