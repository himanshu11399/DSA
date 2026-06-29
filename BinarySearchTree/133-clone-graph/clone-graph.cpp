/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* node, Node* clone, unordered_map<Node*, Node*>& mpp) {
        if ((node && !clone) || (!node && clone)) 
            return;
        for (Node* it : node->neighbors) {
            if (mpp.find(it) == mpp.end()) {
                Node* newclone = new Node(it->val);
                mpp[it] = newclone;
                clone->neighbors.push_back(newclone);
                dfs(it, newclone, mpp);
            } else {
                clone->neighbors.push_back(mpp[it]);
                
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;
        }
        unordered_map<Node*, Node*> mpp;
        Node* clone = new Node(node->val);
        mpp[node] = clone;
        dfs(node, clone, mpp);
        return clone;
    }
};