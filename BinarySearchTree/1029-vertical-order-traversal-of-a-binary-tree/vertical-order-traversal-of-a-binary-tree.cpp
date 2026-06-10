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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) {
            return ans;
        }
        map<int, map<int, multiset<int>>> mpp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            TreeNode* curr = it.first;
            int row = it.second.first;
            int col = it.second.second;

            mpp[col][row].insert(curr->val);
            if (curr->left) {
                q.push({curr->left, {row + 1, col - 1}});
            }
            if (curr->right) {
                q.push({curr->right, {row + 1, col + 1}});
            }
        }

        // Build ANS
        for (auto it : mpp) {
            vector<int> res;
            for (auto temp : it.second) {
                res.insert(res.end(),temp.second.begin(), temp.second.end());
            }
            ans.push_back(res);
        }
        return ans;
    }
};