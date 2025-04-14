//question link: https://leetcode.com/problems/rotate-list/description/
//QUESTION 1: ROTATE LL
//CODE->
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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL||head->next == NULL||k == 0) return head;
        //make a circular linked list, i.e. join last node to first node, 
        //last->next=head
        //also count no of nodes
        int length = 1;
        ListNode* tail = head;
        while(tail->next!=nullptr){
            length++;
            tail=tail->next;
        }
         //you are at last node->tail
        tail->next=head;
        //now you have a circular linked list
        k=k% length;
        int end = length-k; //to get end of linked list
        //now we just have to separate this end from the next linked element
        while(end--)tail=tail->next;
        //now tail points to end element
          head = tail->next;//next element after end becomes first element
          tail->next = NULL;//break loop
        
         return head;
       
    }
};
//APPROACH->make it a circular linked list(i.e. join first to last), and then make the head, k%n
//TC:O(N),SC:O(1)

//question link: https://leetcode.com/problems/copy-list-with-random-pointer/ 
//QUESTION 2: COPY LIST WITH RANDOM POINTERS
//CODE->
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

M-I
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        unordered_map<Node *,Node *>mpp;
        while(temp!=nullptr){
            Node* newNode = new Node(temp->val);
            mpp[temp]=newNode;
            temp=temp->next;
        }
        temp= head;
        while(temp!=nullptr){
                Node* copyNode = mpp[temp];
                copyNode->next=mpp[temp->next];
                copyNode->random = mpp[temp->random];
                temp=temp->next;
        }
        return mpp[head];
    }
};
//TC:O(2N),O(N)(hash map+O(N)(Required)
*/
//MII
class Solution {
public:
    void insertInBetween(Node* head) {
        Node* temp = head;
        while (temp != nullptr) {
            Node* copyNode = new Node(temp->val);
            copyNode->next = temp->next;
            temp->next = copyNode;
            temp = copyNode->next;
        }
    }

    void copyRandomPointers(Node* head) {
        Node* temp = head;
        while (temp != nullptr) {
            Node* copyNode = temp->next;
            if (temp->random) {
                copyNode->random = temp->random->next;
            }
            temp = temp->next->next;
        }
    }

    Node* separateCopiedList(Node* head) {
        Node* dummy = new Node(-1);
        Node* copyTail = dummy;
        Node* temp = head;
        while (temp != nullptr) {
            Node* copyNode = temp->next;
            copyTail->next = copyNode;
            copyTail = copyTail->next;

            temp->next = copyNode->next;  // Restore original list
            temp = temp->next;
        }
        return dummy->next;
    }

    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        insertInBetween(head);
        copyRandomPointers(head);
        return separateCopiedList(head);
    }
};
//APPROACH->(Weave method)

          //->Insert copy nodes in between
          //->connect random pointer
          //->connect next pointer
//TC:O(3N),SC:O(N)
