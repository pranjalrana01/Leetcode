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

    ListNode* reverse(ListNode* head){
        if(head -> next == NULL){
            return head;
        }

        ListNode* newhead = reverse(head -> next);
        head-> next-> next = head;
        head -> next = NULL;
        return newhead;
    }
    ListNode* reverseList(ListNode* head) {
        if(head == NULL)return NULL;
       return reverse(head);
    }
};