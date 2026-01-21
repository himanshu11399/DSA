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
    bool findTarget(TreeNode* root, int k) {
        set<int> st;
        TreeNode* curr = root;
        queue<TreeNode*> q;
        q.push(curr);
        while (!q.empty()) {
            TreeNode* it = q.front();
            q.pop();
            int val = it->val;
            int d = k - val;
            if (st.find(d) != st.end()) {
                return true;
            }
            st.insert(it->val);
            if (it->left) {
                q.push(it->left);
            }
            if (it->right) {
                q.push(it->right);
            }
        }
        return false;
    }
};