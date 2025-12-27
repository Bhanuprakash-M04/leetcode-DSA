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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0)
            return NULL;
        ListNode* first=lists[0];
        for(int i=1;i<n;i++){
            ListNode* second=lists[i];
            first=merge(first,second);
        }
        return first;
    }
    ListNode* merge(ListNode* head1,ListNode* head2){
        ListNode* dummy=new ListNode(-1);
        ListNode* curr=dummy;
        while(head1 && head2){
            if(head1->val<head2->val){
                curr->next=head1;
                curr=head1;
                head1=head1->next;
            }
            else{
                curr->next=head2;
                curr=head2;
                head2=head2->next;
            }
        }
        if(head1){
            curr->next=head1;
        }
        if(head2){
            curr->next=head2;
        }
        return dummy->next;
    }
};