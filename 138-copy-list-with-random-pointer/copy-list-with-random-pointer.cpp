/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertAtTail(Node* &head , Node* & tail , int val){
        Node* newNode = new Node(val);
        
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
    }
    // Node* copyRandomList(Node* head) {
    //      Node* cloneHead = NULL;
    //     Node* cloneTail = NULL;
        
    //     Node* temp = head;
        
    //     while (temp !=NULL){
    //         insertAtTail(cloneHead , cloneTail , temp -> val);
    //         temp = temp -> next;
    //     }
        
    //     //step2 create a map to store original node and clone node linking
        
    //     unordered_map<Node* , Node*>oldToNewNode;
    //     Node* originalNode = head;
    //     Node* cloneNode = cloneHead;
        
    //     while(originalNode != NULL){
    //         oldToNewNode[originalNode] = cloneNode;
    //         originalNode = originalNode -> next;
    //         cloneNode = cloneNode -> next;
    //     }
        
    //     originalNode = head;
    //     cloneNode = cloneHead;
        
    //     while(originalNode != NULL){
    //         cloneNode -> random = oldToNewNode[originalNode -> random];
    //         cloneNode = cloneNode -> next;
    //         originalNode = originalNode -> next;
    //     }
        
    //     return cloneHead;
        
        
    
    Node* copyRandomList(Node* head){
        
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        Node* temp = head;

       while(temp != NULL){
            insertAtTail(cloneHead , cloneTail , temp -> val);
            temp = temp -> next;
       }

       //step2 change pointers of the linked list

       Node* originalNode = head;
       Node* cloneNode = cloneHead;

       while(originalNode != NULL && cloneNode != NULL){
          Node* next = originalNode -> next;
          originalNode -> next = cloneNode;
          originalNode = next;

          next = cloneNode -> next;
          cloneNode -> next = originalNode;
          cloneNode = next;
       }

         temp = head;
       while(temp != NULL){
           if(temp -> next != NULL){
               temp -> next -> random = temp -> random ? temp -> random -> next : temp -> random;
           }
           temp = temp -> next -> next;
       }
           
      originalNode = head;
      cloneNode = cloneHead;

       while(originalNode != NULL && cloneNode != NULL){
           originalNode -> next = cloneNode -> next;
           originalNode = originalNode -> next;
           if(originalNode !=NULL){
           cloneNode -> next = originalNode -> next;
            }
            cloneNode = cloneNode -> next;
       }
       return cloneHead;


    }
};