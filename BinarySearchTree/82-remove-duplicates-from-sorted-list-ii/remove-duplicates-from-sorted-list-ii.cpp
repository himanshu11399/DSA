/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        ListNode* curr = head;

        while (curr) {
            if (curr->next && curr->val == curr->next->val) {
                int duplicate = curr->val;

                while (curr && curr->val == duplicate) {
                    ListNode*delNode=curr;
                    curr = curr->next;
                    delete delNode;
                }

            } else {
                temp->next = curr;
                temp = temp->next;
                curr = curr->next;
                temp->next=nullptr;
            }
        }
        return dummy->next;
    }
};