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
        Node* dummy = new Node(0);
        Node* clone = dummy;
        Node* temp = head;

        // Add the new duplicate node in the Linklist
        while (temp != NULL) {
            Node* newnode = new Node(temp->val);
            newnode->next = temp->next;
            temp->next = newnode;
            temp = newnode->next;
        }

        // Add the Random POinters
        Node* temp1 = head;
        while (temp1 != NULL) {
            if (temp1->random) {
                temp1->next->random = temp1->random->next;
            } else {
                temp1->next->random = NULL;
            }
            temp1 = temp1->next->next;
        }

        // Delink the duplicate node and generate a replica
        Node* temp2 = head;
        while (temp2 != NULL) {
            clone->next = temp2->next;
            temp2->next = temp2->next->next;
            temp2 = temp2->next;
            clone = clone->next;
        }
        return dummy->next;
    }
};