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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL){
            return ans;
        }

        map<int,int>mpp;
        queue<pair<int,TreeNode*>>q;
        q.push({0,root});

        while(!q.empty()){
            auto [lvl,curr]=q.front();
            q.pop();
            if(mpp.find(lvl)==mpp.end()){
                mpp[lvl]=curr->val;
            }else{
                mpp[lvl]=curr->val;
            }

            if(curr->left){
                q.push({lvl+1,curr->left});
            }

            if(curr->right){
                q.push({lvl+1,curr->right});
            }
        }
        
        for(auto it:mpp){
            ans.push_back(it.second);
        }
return ans;
    }
};