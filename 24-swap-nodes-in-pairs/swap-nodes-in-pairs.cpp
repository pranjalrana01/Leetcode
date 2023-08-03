class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* node = new ListNode(-1);
        ListNode* curr = head,* pre = node;
        while(curr != NULL && curr->next != NULL) {
            pre->next = curr->next;
            curr->next = curr->next->next;
            pre->next->next = curr;

            curr = curr->next;
            pre = pre->next->next;
        }
        return node->next;

    }
};