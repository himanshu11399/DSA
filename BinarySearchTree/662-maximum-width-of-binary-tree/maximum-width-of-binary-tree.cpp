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
   typedef unsigned long long ll;
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        queue<pair<TreeNode*, ll>> q;
        q.push({root, 0});
        int maxwidth = 0;

        while (!q.empty()) {
            int n = q.size();

            int firstIndex = q.front().second;
            int secondIndex = q.back().second;

            maxwidth = max(maxwidth, (secondIndex - firstIndex) + 1);

            for (ll i = 0; i < n; i++) {
                auto it = q.front();
                q.pop();

                TreeNode* curr = it.first;
                ll idx = it.second;

                if (curr->left) {
                    q.push({curr->left, (2 * idx) + 1});
                }
                if (curr->right) {
                    q.push({curr->right, (2 * idx) + 2});
                }
            }
        }
        return maxwidth;
    }
};