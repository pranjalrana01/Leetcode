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
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode* start = new ListNode();
//         start -> next = head;
//         ListNode* slow = start;
//         ListNode* fast = start;

//         for(int i=1 ; i<=n ; i++){
//             fast = fast -> next;
//         }
//         while(fast -> next != NULL){
//             fast = fast -> next;
//             slow = slow -> next;
//         }

//         slow -> next = slow -> next -> next;
//         return start -> next;
//     }
// };


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* ptr = head;
        int counter =0;
        while(ptr!=NULL)
        {
            counter++;
            ptr = ptr->next;
        }
        if(head ==NULL || head->next == NULL)
        {
            return NULL;
        }
        if(counter - n == 0)
         {
             head = head->next;
             return head;
         }
        ListNode* temp=head;
        ListNode* slow=head;
        for(int i=0;i<counter-n;i++)
        {
            slow = temp;
            temp = temp->next;
        }
        slow->next = temp->next;
        return head;  
    }
};