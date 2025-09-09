/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == NULL) {
            return ans;
        }
        queue<pair<TreeNode*, int>> q;
        int currlevel = 1;
        q.push({root, currlevel});
        vector<int> res;

        while (!q.empty()) {
            auto [curr, level] = q.front();
            q.pop();
           
            if (level > currlevel) {
                if(currlevel%2==0){
                    reverse(res.begin(),res.end());
                }
                ans.push_back(res);
                res.clear();
                currlevel = level;
            }
            res.push_back(curr->val);

            if (curr->left != NULL) {
                q.push({curr->left, level + 1});
            }
            if (curr->right != NULL) {
                q.push({curr->right, level + 1});
            }
        }
        if(!res.empty()){
            if(currlevel%2==0){
                reverse(res.begin(),res.end());
            }
            ans.push_back(res);
        }
        return ans;
    }
};