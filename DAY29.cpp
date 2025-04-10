//question link:  https://bit.ly/3dyXL6m
//QUESTION 1: FIND LENGTH OF LOOP
//CODE->
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void loopHere(Node *head, Node *tail, int position) {
    if (position == 0)
        return;

    Node *walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}


// } Driver Code Ends

/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        struct Node* slow = head;
        struct Node* fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast=fast->next->next;
            if(fast==slow){
                //i.e. a loop exists, now move both slow and fast at same speed
                int cnt = 1;
                 struct Node* temp = slow->next;
                while(temp!=slow){
                    cnt++;
                    temp=temp->next;
                }
                return cnt;
            }
        }
        
        return 0;
    }
};

//APPROACH->
              // Use fast and slow pointers to detect the cycle (Floyd's algorithm).
              //Once they meet, count the number of nodes by moving one temp pointer until it meets the other again.
//TC:O(N),O(1)

//question link: https://leetcode.com/problems/palindrome-linked-list/
//QUESTION 2: CHECK PALINDROME LINKED LIST
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
    ListNode* reverseLL(ListNode* head) {

        ListNode* prev = nullptr;
        ListNode* current = head;
        ListNode* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;
        // to get middle of LL
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // if no of elements are odd, then fast will be at the last element
        // skip the  middle node
        // if we compare odd halves we will get wrong result even if it is a palindrome 
        // for eg in 1-2-3-2-1, 1-2-3 part will get compared with 1-2(reverse of 2-1)and will return false 
        // if we do reverse(slow->next)then ->in even cases we get stuck 
        // for eg in 1-2-2-1, here slow will point to second middle node which is index 2(i.e.second 2), 
        // then slow->next will be 1 so 1-2-2 will be compared with 1
        // so it is better to skip middle node in case of odd length entirely
        if (fast != nullptr) {
            slow = slow->next;
        }

        // reverse part after slow

        ListNode* secondHalf = reverseLL(slow);
        ListNode* temp = head;
        // compare data of both
        while (secondHalf != nullptr) {
            if (temp->val != secondHalf->val)
                return false;
            temp = temp->next;
            secondHalf = secondHalf->next;
        }
        return true;
    }
};
//APPROACH->// Use slow and fast pointers to reach the middle of the list.
            //Reverse the second half and compare it with the first half to check for palindrome.
//TC:O(N),O(1)
