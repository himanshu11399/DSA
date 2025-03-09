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
void inorder(TreeNode*root,vector<int>&result){
    

        TreeNode*curr=root;
        while(curr!=NULL){
            if(curr->left==NULL){
                result.push_back(curr->val);
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
        }
}
    bool isValidBST(TreeNode* root) {
        vector<int>result;
        inorder(root,result);
        int element=result[0];
        for(int i=1;i<result.size();i++){
            if(element<result[i]){
                element=result[i];
            }else{
                return false;
            }
        }
        return true;
    }
};