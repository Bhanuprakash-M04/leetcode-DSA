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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0)
            return head;
        ListNode* curr=head;
        int cnt=1;
        while(curr->next){
            curr=curr->next;
            cnt++;
        }
        k=k%cnt;
        if(k==0)
            return head;
        int len=cnt-k;
        ListNode* tmp=head;
        ListNode* prev=NULL;
        while(tmp->next && len--){
            prev=tmp;
            tmp=tmp->next;
        }
        prev->next=NULL;
        ListNode* newHead=tmp;
        while(tmp->next){
            tmp=tmp->next;
        }
        tmp->next=head;
        return newHead;
    }
};