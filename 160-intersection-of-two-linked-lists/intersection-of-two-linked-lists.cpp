/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* temp = headA;
        ListNode* temp1 = headB;

        int a = 0;
        int b = 0;
        while (temp != NULL) {
            a++;
            temp = temp->next;
        }
        temp = headA;
        while (temp1 != NULL) {
            b++;
            temp1 = temp1->next;
        }
        temp1 = headB;

        while(a<b){
            b--;
            temp1=temp1->next;
        }
        while(a>b){
            a--;
            temp=temp->next;
        }

        while(temp!=NULL && temp1!=NULL){
            if(temp==temp1){
                return temp;
            }else{
                temp=temp->next;
                temp1=temp1->next;
            }
        }

   return NULL;
    }
};