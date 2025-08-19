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
        unordered_set<ListNode*>myset;
        ListNode* tmp=head;
        while(tmp!=NULL){
            if(myset.find(tmp)!=myset.end()){
                return tmp;
            }
            myset.insert(tmp);
            tmp=tmp->next;
        }
        return NULL;
    }
};