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
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            ListNode* head=lists[i];
            while(head){
                ListNode* curr=head;
                pq.push(curr->val);
                head=head->next;
            }
        }
        ListNode* dummy=new ListNode(-1);
        ListNode* curr=dummy;
        while(!pq.empty()){
            ListNode* newNode=new ListNode(pq.top());
            pq.pop();
            curr->next=newNode;
            curr=newNode;
        }
        return dummy->next;
    }
};