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
    ListNode* findK(ListNode* head,int k){
        ListNode* Kth=head;
        while(k>1 && head!=NULL){
            head=head->next;
            k--;
        }
        if(head==NULL)
            return Kth;
        Kth=head;
        return Kth;
    }
    void reverseNode(ListNode* head){
        ListNode* prev=NULL;
        ListNode* curr=NULL;
        ListNode* temp=head;
        while(temp!=NULL){
            curr=temp;
            temp=temp->next;
            curr->next=prev;
            prev=curr;
        }
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp!=NULL){
            ListNode* Kth=findK(temp,k);
            if(Kth==temp){
                if(prev){
                    prev->next=temp;
                }
                break;
            }
            else{
                ListNode* nextNode=Kth->next;
                Kth->next=NULL;
                reverseNode(temp);
                if(temp==head)
                    head=Kth;
                else
                    prev->next=Kth;
                prev=temp;
                temp=nextNode;
                
            }
        }
        return head;
    }
};