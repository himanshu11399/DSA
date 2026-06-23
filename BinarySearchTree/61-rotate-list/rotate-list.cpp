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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int len = 0;
        ListNode* temp = head;
        while (temp) {
            len++;
            temp = temp->next;
        }
        if (k % len == 0) {
            return head;
        }
        temp = head;

        ListNode* dummy = new ListNode(0);
        ListNode* prev = dummy;

        for (int i = 0; i < len-(k%len)-1; i++) {
            temp = temp->next;
        }

        prev->next = temp->next;
        temp->next = NULL;

        while (prev && prev->next) {
            prev = prev->next;
        }
        prev->next = head;
        return dummy->next;
    }
};