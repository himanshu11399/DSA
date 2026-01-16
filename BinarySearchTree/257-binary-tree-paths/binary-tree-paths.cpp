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
    void solve(TreeNode* root, vector<string>& res, string ans) {
        if (!root)
            return;

        if(ans!="") ans=ans+"->";
        ans=ans+to_string(root->val);

        if (!root->left && !root->right) {
            res.push_back(ans);
            return;
        }

        solve(root->left, res, ans);
        solve(root->right, res, ans);

        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root)
            return res;
        solve(root, res, "");
        return res;
    }
};