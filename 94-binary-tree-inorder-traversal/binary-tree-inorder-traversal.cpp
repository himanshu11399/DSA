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
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == NULL)
            return ans;

        while (root) {

            // left does not exist;
            if (root->left == NULL) {
                ans.push_back(root->val);
                root = root->right;
            } else { // if left is exist
                TreeNode* curr = root->left;
                while (curr->right &&
                       curr->right != root) { // It is used to check the Left is
                                              // traversed or not
                    curr = curr->right;
                }

                // if left is traversed
                if (curr->right == root) { 
                    curr->right = NULL;
                    ans.push_back(root->val);
                    root = root->right;
                } else {// If the left is not traversed
                    curr->right = root;
                    root = root->left;
                }
            }
        }

        return ans;
    }
};