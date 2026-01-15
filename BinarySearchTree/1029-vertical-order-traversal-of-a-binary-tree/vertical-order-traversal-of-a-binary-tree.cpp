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
        vector<vector<int>> res;
        if (!root)
            return res;

        map<int, map<int, multiset<int>>> notes;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root,
                {
                    0,
                    0,
                }});

        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            TreeNode* curr = p.first;
            int row = p.second.first;
            int col = p.second.second;

            notes[col][row].insert(curr->val);

            if (curr->left) {
                q.push({curr->left, {row + 1, col - 1}});
            }

            if (curr->right) {
                q.push({curr->right, {row + 1, col + 1}});
            }
        }

        for (auto p : notes) {
            vector<int> ans;
            for (auto q : p.second) {
                ans.insert(ans.end(), q.second.begin(), q.second.end());
            }
            res.push_back(ans);
        }

        return res;
    }
};