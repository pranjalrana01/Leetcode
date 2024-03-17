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
 class cmp{
     public:
        bool operator() (ListNode* a, ListNode*b){
            return a->val > b->val;
        }
 };
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp>pq;

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        for(int i=0 ; i<lists.size();i++){
            if(lists[i] != NULL){
                pq.push(lists[i]);
            }
        }

        while(pq.size()){
            ListNode* node = pq.top();
            tail -> next = node;
            tail = node;
            pq.pop();
            if(node -> next != NULL)pq.push(node -> next);
        }

        return dummy -> next;
    }
};