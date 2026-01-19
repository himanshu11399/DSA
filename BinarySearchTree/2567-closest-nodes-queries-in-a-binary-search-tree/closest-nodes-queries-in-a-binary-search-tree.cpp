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
    void inorder(TreeNode* root, set<int>& st) {
        if (!root)
            return;
        inorder(root->left, st);
        st.insert(root->val);
        inorder(root->right, st);
    }

    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        vector<vector<int>> ans;
        set<int> st;
        inorder(root, st);

        for (int i = 0; i < queries.size(); i++) {
            int floor = -1, ceil = -1;
            int x=queries[i];

            auto it1 = st.lower_bound(x);
            if (it1 != st.end()) {
                ceil = *it1;
            }

            // Floor
            auto it2 = st.upper_bound(x);
            if (it2 != st.begin()) {
                it2--;
                floor = *it2;
            }

            ans.push_back({floor, ceil});
        }
        return ans;
    }
};