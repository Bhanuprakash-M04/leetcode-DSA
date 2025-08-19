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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* odd=head;
        ListNode* oddHead=odd;
        ListNode* even=head->next;
        ListNode* evenHead=even;
        ListNode* temp=head->next->next;
        while(temp!=NULL){
            odd->next=temp;
            odd=odd->next;
            temp=temp->next;
            if(temp!=NULL){
                even->next=temp;
                even=even->next;
                temp=temp->next;
            }
        }
        odd->next=evenHead;
        even->next=NULL;
        return head;
    }
};