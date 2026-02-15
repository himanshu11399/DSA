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
        if (!root)
            return ans;

        //{col,row,value}
        map<int, map<int, multiset<int>>> mpp;
        //{Node*,row,col}
        queue<pair<TreeNode*, pair<int, int>>> st;

        st.push({root, {0, 0}});

        while (!st.empty()) {
            auto q = st.front();
            st.pop();

            TreeNode* curr = q.first;
            int row = q.second.first;
            int col = q.second.second;

            mpp[col][row].insert(curr->val);

            if (curr->left) {
                st.push({curr->left, {row + 1, col - 1}});
            }
            if (curr->right) {
                st.push({curr->right, {row + 1, col + 1}});
            }
        }

        for (auto it : mpp) {
            vector<int> res;
            for (auto q : it.second) {
                res.insert(res.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(res);
        }
        return ans;
    }
};