/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void dfs(TreeNode* root, string& ans) {
        if (!root) {
            ans += "NULL,";
            return;
        }
        ans += to_string(root->val) + ",";
        dfs(root->left, ans);
        dfs(root->right, ans);
    }

    TreeNode* dfs2(queue<string>& q) {
        string it = q.front();
        q.pop();
        if (it == "NULL")
            return NULL;

        TreeNode* root = new TreeNode(stoi(it));
        root->left = dfs2(q);
        root->right = dfs2(q);
        return root;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        dfs(root, ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string temp;
        for (auto& c : data) {
            if (c == ',') {
                q.push(temp);
                temp.clear();
            } else {
                temp += c;
            }
        }
        return dfs2(q);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));