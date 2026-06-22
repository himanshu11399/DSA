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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size = 0;
        ListNode* temp = head;
        while (temp) {
            size++;
            temp = temp->next;
        }
        int pos = size - n;
        if (pos == 0) {
            head = head->next;
        } else {
            ListNode* p = head;
            ListNode* q = head->next;
            for (int i = 0; i < pos - 1; i++) {
                p = p->next;
                q = q->next;
            }
            p->next = q->next;
            delete q;
        }
        return head;
    }
};