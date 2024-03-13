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
ListNode* Kreverse(ListNode* head,int k,int n){

        if(n<k)return head;
        ListNode* next=NULL;
        ListNode* curr=head;
        ListNode* prev=NULL;
        int cnt=0;
        while(cnt<k and curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            cnt++;
        }
        if(next!=NULL)head->next=Kreverse(next,k,n-k);

        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL){
            return NULL;
        }

         ListNode* temp=head;
        int n=0;
        while(temp){
            temp=temp->next;
            n++;
        }
        return Kreverse(head,k,n);
    }
};