/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
unordered_map<TreeNode*,TreeNode*>parent;

void inorder(TreeNode*root){
    if(!root) return;

    if(root->left){
        parent[root->left]=root;
        inorder(root->left);
    }
    if(root->right){
        parent[root->right]=root;
        inorder(root->right);
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;

        inorder(root);
        BFS(target,k,ans);
        return ans;
    }
    private:

    void BFS(TreeNode*target,int k,vector<int>&ans){
        queue<TreeNode*>q;
        q.push(target);

        unordered_set<int>visited;
        visited.insert(target->val);

        while(!q.empty()){
           int n=q.size();
           if(k==0){
            break;
           }

           while(n--){
            TreeNode*node=q.front();
            q.pop();

            //for left
            if(node->left!=NULL && !visited.count(node->left->val) ){
                q.push(node->left);
                visited.insert(node->left->val);
            }

            //for right
            if(node->right!=NULL && !visited.count(node->right->val) ){
                q.push(node->right);
                visited.insert(node->right->val);
            }

            if(parent.count(node) && !visited.count(parent[node]->val) ){
                q.push(parent[node]);
                visited.insert(parent[node]->val);
            }
           }k--;
        }
    
        while(!q.empty()){
            TreeNode*node=q.front();
            q.pop();
            ans.push_back(node->val);
        }

    }   
};