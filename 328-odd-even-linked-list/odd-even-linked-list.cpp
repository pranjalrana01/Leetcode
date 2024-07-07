class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head -> next == NULL)return head;

        ListNode* starteven = head;
        ListNode* even = head;
        ListNode* startodd = head -> next;
        ListNode* odd = head -> next;

        while(even -> next -> next != NULL && odd -> next -> next!= NULL){
            even -> next = even -> next -> next;
            even = even -> next;
            odd -> next = odd -> next -> next;
            odd = odd -> next;
        }

        if(odd -> next){
            even -> next = odd -> next;
            even = even -> next;
        }
        if(even -> next){
            odd -> next = even -> next;
            odd = odd -> next;
        }

            odd -> next = NULL;
            even -> next = startodd;
            return starteven;

    }
};