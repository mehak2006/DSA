//question link: https://bit.ly/3QD4hHs
//QUESTION 1: Doubly linked list Insertion at given position

//CODE->
/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

// Function to insert a new node at given position in doubly linked list.
class Solution {
  public:
    
   
    Node *addNode(Node *head, int pos, int data) {
        Node* newnode = new Node(data);
        Node* temp = head;
        
        if(!head)
            return newnode;
            
        for(int i=0;i<pos;i++) {
            temp = temp->next;
        }
        
        if(!temp->next) {
            temp->next = newnode;
            newnode->prev = temp;
        }
        else {
            Node* temp1 = temp->next;
            temp->next = newnode;
            newnode->prev = temp;
            newnode->next = temp1;
            temp1->prev = newnode;
        }
        
        return head;
    }
};
//APPROACH: Iterate through the linked list, returning true if temp->data == key, else return false after reaching the end.
//TC:O(N),SC:O(1)

//question link: https://bit.ly/3Epriup
//QUESTION 2: SEARCH IN LINKED LIST
//CODE->
class Solution {
  public:
    // Function to count nodes of a linked list.
    bool searchKey(int n, Node* head, int key) {
        // Code here
    Node*temp = head;

    while(temp){
    if(temp->data==key)return true;
    temp=temp->next;
    }
    return false;
}
};
//APPROACH:Traverse the linked list while checking if temp->data == key, returning true if found; otherwise, return false after traversal.
//TC:O(N),SC:O(1)
