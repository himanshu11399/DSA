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

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;

        if(root==NULL){
            return ans;
        }

        queue<pair<TreeNode*,int>>q;
        q.push({root,1});
        int currlevel=1;
        
        vector<int>res;
        while(!q.empty()){
            auto [curr,level]=q.front();
            q.pop();

            if(level>currlevel){
                ans.push_back(res);
                res={};
                currlevel=level;
            }

            res.push_back(curr->val);

            if(curr->left!=NULL){
                q.push({curr->left,level+1});
            }

            if(curr->right!=NULL){
                q.push({curr->right,level+1});
            }
        }
        if(!res.empty()){
            ans.push_back(res);
        }
            return ans;
        
    }
};