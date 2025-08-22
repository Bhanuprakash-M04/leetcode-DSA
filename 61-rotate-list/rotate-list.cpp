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
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* curr=head;
        int cnt=1;
        while(curr->next){
            curr=curr->next;
            cnt++;
        }
        k=k%cnt;
        while(k--){
            ListNode* tmp=head;
            ListNode* prev=NULL;
            while(tmp->next){
                prev=tmp;
                tmp=tmp->next;
            }
            prev->next=NULL;
            tmp->next=head;
            head=tmp;
        }
        return head;
    }
};