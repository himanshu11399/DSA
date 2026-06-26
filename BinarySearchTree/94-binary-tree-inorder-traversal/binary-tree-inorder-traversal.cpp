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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (!root)
            return ans;
        TreeNode* curr = root;
        while (curr) {
            // If left not exist
            if (!curr->left) {
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                // Left is Exist
                TreeNode* temp = curr->left;
                while (temp->right && temp->right != curr) {
                    temp = temp->right;
                }

                // Not Traverse
                if (temp->right == NULL) {
                    temp->right = curr;
                    curr = curr->left;
                } else { // Traverse
                    curr->left = NULL;
                }
            }
        }
        return ans;
    }
};