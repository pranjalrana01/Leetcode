class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
         if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* node = new ListNode(-1);
        ListNode* curr = head,* prev = node;

        while(curr != NULL && curr -> next != NULL){
            prev -> next = curr -> next;
            curr -> next = curr -> next -> next;

            prev -> next -> next = curr;
            curr = curr -> next;
            prev = prev -> next -> next;
        }
        return node -> next;
    }
};