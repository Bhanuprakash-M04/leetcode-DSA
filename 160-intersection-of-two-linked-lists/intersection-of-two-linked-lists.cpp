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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL)
            return NULL;
        unordered_set<ListNode*>myset;
        ListNode* temp=headA;
        while(temp){
            myset.insert(temp);
            temp=temp->next;
        }
        temp=headB;
        while(temp){
            if(myset.find(temp)!=myset.end()){
                return temp;
            }
            temp=temp->next;
        }
        return NULL;
    }
};