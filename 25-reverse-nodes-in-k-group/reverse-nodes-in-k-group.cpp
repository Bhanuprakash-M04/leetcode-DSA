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
    ListNode* findknode(ListNode* head,int k){
        k=k-1;
        while(head!=NULL && k>0){
            k--;
            head=head->next;
        }
        return head;
    }
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* prev=NULL;
        ListNode* curr=NULL;
        ListNode* temp=head;
        while(temp){
            curr=temp;
            temp=temp->next;
            curr->next=prev;
            prev=curr;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* temp=head;
        ListNode* prevNode=NULL;
        while(temp){
            ListNode* kth=findknode(temp,k);
            if(kth==NULL){
                if(prevNode)
                    prevNode->next=temp;
                break;
            }
            ListNode* nextNode=kth->next;
            kth->next=NULL;
            kth=reverse(temp);
            if(head==temp){
                head=kth;
            }
            else{
                prevNode->next=kth;
            }
            prevNode=temp;
            temp=nextNode;
        }
        return head;
    }
};