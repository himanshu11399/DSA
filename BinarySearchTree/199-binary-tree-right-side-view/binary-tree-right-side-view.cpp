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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;

        map<int, int> mpp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            TreeNode* curr = p.first;
            int lvl = p.second;

            mpp[lvl] = curr->val;
            if (curr->left) {
                q.push({curr->left, lvl + 1});
            }
            if (curr->right) {
                q.push({curr->right, lvl + 1});
            }
        }
        for (auto it : mpp) {
            res.push_back(it.second);
        }
        return res;
    }
};