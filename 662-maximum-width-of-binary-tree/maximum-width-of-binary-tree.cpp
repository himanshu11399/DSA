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
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int maxwidth = 0;

        while (!q.empty()) {
            int size = q.size();
            unsigned long long stIdx = q.front().second;
            unsigned long long endIdx = q.back().second;

            maxwidth = max(maxwidth, (int)(endIdx - stIdx + 1));

            for (int i = 0; i < size; i++) {
                auto [currNode, currIdx] = q.front();
                q.pop();
                if (currNode->left) {
                    q.push({currNode->left, 2 * currIdx + 1});
                }
                if (currNode->right) {
                    q.push({currNode->right, 2 * currIdx + 2});
                }
            }
        }
        return maxwidth;
    }
}; 