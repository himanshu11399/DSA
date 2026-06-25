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
    int sumNumbers(TreeNode* root) {
        if (!root)
            return 0;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int ans = 0;

        while (!q.empty()) {
            auto [curr, sum] = q.front();
            q.pop();
            sum = (sum * 10) + curr->val;
            if (!curr->left && !curr->right) {
                ans += sum;
            }
            if (curr->left) {
                q.push({curr->left, sum});
            }
            if (curr->right) {
                q.push({curr->right, sum});
            }
        }
        return ans;
    }
};