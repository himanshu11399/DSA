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
    ListNode* reverse(ListNode* start, ListNode* end) {
        ListNode*stop=end->next;

        ListNode* curr = start;
        ListNode* prev = end->next;

        while (curr != stop) {
            ListNode* temp2 = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp2;
        }
        return prev;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left > right || left == right)
            return head;

        ListNode* temp = head;
        ListNode* start = NULL;
        ListNode* end = NULL;
        ListNode* temphead = NULL;

        int count = 1;

        while (temp) {
            if (count == left) {
                start = temp;
            }
            if (count == left - 1) {
                temphead = temp;
            }
            if (count == right) {
                end = temp;
                break;
            }
            temp = temp->next;
            count++;
        }
        if (!start || !end)
            return head;
        ListNode* newlist = reverse(start, end);

        if (temphead) {
            temphead->next = newlist;
        } else {
            head = newlist;
        }
        return head;
    }
};