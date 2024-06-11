class Solution {
public:
ListNode* kReverse(ListNode* head,int k, int n){
    if(n < k)return head;
    
    ListNode* curr = head;
    ListNode* next1 = NULL;
    ListNode* prev = NULL;

    int cnt = 0;
    while(cnt <k && curr != NULL){
        next1 = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next1;
        cnt++;
    }
    if(next1 != NULL)head -> next = kReverse(next1, k, n-k);
    return prev;

}
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL){
            return NULL;
        }
        int n =0;
        ListNode* temp = head;
        while(temp){
            temp = temp -> next;
            n++;
        }

        return kReverse(head, k, n);
    }
};