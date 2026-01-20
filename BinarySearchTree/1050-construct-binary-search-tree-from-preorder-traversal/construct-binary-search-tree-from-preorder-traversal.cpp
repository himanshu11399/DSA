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
    int find(vector<int>& inorder, int st, int end, int target) {
        for (int i = st; i <= end; i++) {
            if (inorder[i] == target) {
                return i;
            }
        }
        return -1;
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& PreIdx,
                    int left, int right) {
        if (left > right)
            return NULL;

        TreeNode* curr = new TreeNode(preorder[PreIdx]);
        int InoIdx = find(inorder, left, right, preorder[PreIdx]);
        PreIdx++;
        curr->left = build(preorder, inorder, PreIdx, left, InoIdx - 1);
        curr->right = build(preorder, inorder, PreIdx, InoIdx + 1, right);
        return curr;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder;
        for (int i = 0; i < preorder.size(); i++) {
            inorder.push_back(preorder[i]);
        }
        sort(inorder.begin(), inorder.end());

        int PreIdx = 0;
        return build(preorder, inorder, PreIdx, 0, inorder.size() - 1);
    }
};