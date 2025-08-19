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
    ListNode* reverse(ListNode* head){
        ListNode* curr=NULL;
        ListNode* prev=NULL;
        ListNode* temp=head;
        while(temp!=NULL){
            curr=temp;
            temp=temp->next;
            curr->next=prev;
            prev=curr;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* second=reverse(slow);
        ListNode* first=head;
        while(second!=NULL){
            if(first->val!=second->val)
                return false;
            first=first->next;
            second=second->next;
        }
        return true;
    }
};