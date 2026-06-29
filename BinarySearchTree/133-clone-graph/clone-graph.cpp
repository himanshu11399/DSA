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
    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;
        }
        unordered_map<Node*, Node*> mpp;
        Node* clone = new Node(node->val);
        mpp[node] = clone;
        queue<pair<Node*, Node*>> q;
        q.push({node, clone});
        while (!q.empty()) {
            auto [original_node, clone_node] = q.front();
            q.pop();

            for (Node* it : original_node->neighbors) {
                if (mpp.find(it) == mpp.end()) {
                    Node* temp = new Node(it->val);
                    mpp[it] = temp;
                    q.push({it, temp});
                }
                clone_node->neighbors.push_back(mpp[it]);
            }
        }

        return clone;
    }
};