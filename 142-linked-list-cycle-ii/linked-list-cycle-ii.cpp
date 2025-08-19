/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // unordered_set<ListNode*>myset;
        // ListNode* tmp=head;
        // while(tmp!=NULL){
        //     if(myset.find(tmp)!=myset.end()){
        //         return tmp;
        //     }
        //     myset.insert(tmp);
        //     tmp=tmp->next;
        // }
        // return NULL;

        if(head==NULL || head->next==NULL || head->next->next==NULL)
            return NULL;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast){
                break;
            }
        }
        if(fast==NULL || fast->next==NULL)
            return NULL;
        slow=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return fast;
    }
};