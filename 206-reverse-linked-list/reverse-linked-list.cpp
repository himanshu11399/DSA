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
    ListNode* reverseList(ListNode* head) {
        ListNode*newlist=NULL;
        while(head!=NULL){
            ListNode*temp=new ListNode(head->val);
            temp->next=newlist;
            newlist=temp;
            head=head->next;
        }
        return newlist;
    }
};