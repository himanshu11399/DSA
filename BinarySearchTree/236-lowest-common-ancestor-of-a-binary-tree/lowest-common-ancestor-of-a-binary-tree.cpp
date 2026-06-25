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
        // it  will store like {child,parent}
        unordered_map<TreeNode*, TreeNode*> mpp;
        queue<TreeNode*> que;
        que.push(root);
        mpp[root] = NULL;
        while (!que.empty()) {
            TreeNode* curr = que.front();
            que.pop();
            if (curr->left) {
                que.push(curr->left);
                mpp[curr->left] = curr;
            }
            if (curr->right) {
                mpp[curr->right] = curr;
                que.push(curr->right);
            }
        }

        unordered_set<TreeNode*> ansector;
        while (p) {
            ansector.insert(p);
            p = mpp[p];
        }

        // Find ansector
        while (q) {
            if (ansector.count(q)) {
                break;
            }
            q = mpp[q];
        }
        return q;
    }
};