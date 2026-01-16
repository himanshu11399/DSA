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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // map<child,parent>
        map<TreeNode*, TreeNode*> parent;

        queue<TreeNode*> que;

        que.push(root);
        parent[root] = NULL;

        while (!que.empty()) {
            TreeNode* curr = que.front();
            que.pop();

            if (curr->left) {
                parent[curr->left] = curr;
                que.push(curr->left);
            }
            if (curr->right) {
                parent[curr->right] = curr;
                que.push(curr->right);
            }
        }

        set<TreeNode*>st;
        while(p){
            st.insert(p);
            p=parent[p];
        }

        while(q){
            if(st.count(q)){
                return q;
            }
            q=parent[q];
        }
        return NULL;
    }
};