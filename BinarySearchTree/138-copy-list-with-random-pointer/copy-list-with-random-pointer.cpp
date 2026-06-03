/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node(-1);
        Node* ans = dummy;

        Node* temp = head;

        // Part-1 Add duplicate Nodes
        while (temp) {
            Node* newnode = new Node(temp->val);
            newnode->next = temp->next;
            temp->next = newnode;
            temp = newnode->next;
        }

        // Part-B Connect Random Pointers
        temp = head;
        while (temp) {
            Node* clone = temp->next;
            if(temp->random){
            clone->random = temp->random->next;
            }
            temp = temp->next->next;
        }

        // Part-C Delink the Clone List
        temp = head;
        while (temp) {
            Node* nextNode = temp->next;
            ans->next = nextNode;
            temp->next = nextNode->next;
            ans = ans->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};