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
    int search(vector<int> arr, int st, int end, int val) {
        for (int i = st; i <= end; i++) {
            if (arr[i] == val) {
                return i;
            }
        }
        return -1;
    }
    TreeNode* helper(vector<int>& in, vector<int>& pos, int left, int right,
                     int& posIdx) {
        if (left > right)
            return NULL;

        TreeNode* root = new TreeNode(pos[posIdx]);
        int inIdx = search(in, left, right, pos[posIdx]);
        posIdx--;

        root->right = helper(in, pos, inIdx+1, right, posIdx);
        root->left = helper(in, pos, left, inIdx-1, posIdx);

        return root;
    }
    TreeNode* buildTree(vector<int>& in, vector<int>& pos) {
        int idx = pos.size() - 1;
        return helper(in, pos, 0, in.size() - 1, idx);
    }
};