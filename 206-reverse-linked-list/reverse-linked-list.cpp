class Solution {
    // private:
    // void reverse(ListNode* &head,ListNode* &curr,ListNode* prev){
    //     if(curr == NULL){
    //         head = prev;
    //         return;
    //     }
    //     ListNode* forward = curr->next;
    //     reverse(head, forward, curr);
    //     curr->next = prev;
    // }
public:
    ListNode* reverseList(ListNode* head) {
       ListNode* prev = NULL;
       ListNode* curr = head;

       while(curr != NULL){
        ListNode* next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
       }

       return prev;
    }
};