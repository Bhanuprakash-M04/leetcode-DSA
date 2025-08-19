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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)
            return head;
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        if(cnt==n)
            return head->next;
        ListNode* curr=head;
        ListNode* prev=NULL;
        int ans=0;
        while(curr!=NULL){
            ans++;
            prev=curr;
            curr=curr->next;
            if(ans==cnt-n){
                prev->next=curr->next;
                delete(curr);
                break;
            }
        }
        return head;
    }
};