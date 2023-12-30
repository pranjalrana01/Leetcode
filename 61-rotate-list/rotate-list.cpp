class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head -> next || k == 0)
            return head;
        int size = 1;
        ListNode* tail = head;
        while(tail->next){
            tail = tail -> next;
            size++;
        }

        int rotate = k%size;
        if(rotate == 0)
            return head;
            
        tail -> next = head;
        rotate = size - rotate - 1;
        ListNode* temp = head;

        while(rotate--){
            temp = temp -> next;
        }
        ListNode* forward = temp->next;
        temp -> next = NULL;

        return forward;

    }
};