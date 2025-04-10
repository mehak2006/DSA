//question link: https://bit.ly/3w6hUaa
//QUESTION 1: REVERSE A DLL
//CODE->
/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
 
        if (head == NULL || head->next == NULL) 
        {
        return head; 
        }
    
    
    DLLNode* back = NULL;  
    DLLNode* current = head;   

    while (current != NULL) {
       
        back = current->prev; 
        current->prev= current->next; 
        current->next = back;          
        current = current->prev; 
    }
    return back->prev;
    }
};
//APPROACH->Traverse the doubly linked list and swap the next and prev pointers for each node.
            //After the loop, the new head is back->prev, which was the last node before reversal.
//TC:O(N),SC:O(1)


//question link: https://bit.ly/3QlEoMx
//QUESTION 2: DELETE IN A DLL
//CODE->
class Solution {
  public:
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int k) {
        if (!head) return nullptr;

        Node* temp = head;
        int count = 1;

        // Move to the k-th node
        while (temp && count < k) {
            temp = temp->next;
            count++;
        }

        if (!temp) return head; // k is out of bounds

        // If the node to delete is head
        if (!temp->prev) {
            head = temp->next;
            if (head) head->prev = nullptr;
        }
        // If the node to delete is in the middle or tail
        else {
            temp->prev->next = temp->next;
            if (temp->next)
                temp->next->prev = temp->prev;
        }

        delete temp;
        return head;
    }
};


//APPROACH->//Start at the head and move to the k-th node.
            //If it’s the first node, update the head. 
            //Otherwise, connect the previous and next nodes to skip the one being deleted.
            //Finally, delete that node.
//TC:O(k),SC:O(1)

