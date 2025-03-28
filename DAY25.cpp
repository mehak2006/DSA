//LINKED LIST

//question link: https://leetcode.com/problems/delete-node-in-a-linked-list/
//QUESTION 1:DELETE NODE IN A LL
//CODE->
class Solution {
public:
  void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
//APPROACH->basically just shifted the contents of node->next into node and then skipped node->next
//TC:O(1),SC:O(1)

//question link: https://bit.ly/3w9pEIt
//QUESTION 2: LINKED LIST INSERTION AT END
//CODE->
class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        // Code here
    if(head==nullptr)return new Node(x);

    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    Node* newNode= new Node(x);
    temp->next=newNode;
    return head;
    }
};

//APPROACH->if empty jsut add node, if not traverse till end then add new node
//TC:O(N),SC:O(1)
