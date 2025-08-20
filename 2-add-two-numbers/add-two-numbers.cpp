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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL && l2==NULL)
            return NULL;
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode* p1=l1;
        ListNode* p2=l2;
        int carry=0;
        ListNode* ans=new ListNode(-1);
        ListNode* dummy=ans;
        while(p1!=NULL && p2!=NULL){
            int sum=p1->val+p2->val+carry;
            carry=sum/10;
            sum=sum%10;
            ListNode* newNode=new ListNode(sum);
            dummy->next=newNode;
            dummy=newNode;
            p1=p1->next;
            p2=p2->next;
        }
        while(p1!=NULL){
            int sum=p1->val+carry;
            carry=sum/10;
            sum=sum%10;
            ListNode* newNode=new ListNode(sum);
            dummy->next=newNode;
            dummy=newNode;
            p1=p1->next;
        }
        while(p2!=NULL){
            int sum=p2->val+carry;
            carry=sum/10;
            sum=sum%10;
            ListNode* newNode=new ListNode(sum);
            dummy->next=newNode;
            dummy=newNode;
            p2=p2->next;
        }
        if(carry!=0){
            ListNode* newNode=new ListNode(carry);
            dummy->next=newNode;
        }
        return ans->next;
    }
};