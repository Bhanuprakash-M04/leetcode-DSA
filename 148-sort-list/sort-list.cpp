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
    ListNode* findmid(ListNode* head){
        ListNode* fast=head->next;
        ListNode* slow=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }
    ListNode* merge(ListNode* list1,ListNode* list2){
        ListNode* dummy=new ListNode(-1);
        ListNode* temp=dummy;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<list2->val){
                temp->next=list1;
                temp=temp->next;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                temp=temp->next;
                list2=list2->next;
            }
        }
        if(list1){
            temp->next=list1;
        }
        else{
            temp->next=list2;
        }
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* middle=findmid(head);
        ListNode* left=head;
        ListNode* right=middle->next;
        middle->next=NULL;
        left=sortList(left);
        right=sortList(right);
        return merge(left,right);
    }
};