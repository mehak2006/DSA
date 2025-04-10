//question link:https://leetcode.com/problems/linked-list-cycle/
//QUESTION 1: DETECT LOOP IN LINKED LIST
//CODE->
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast=fast->next->next;
            if(fast==slow)return true;
        }
        return false;
    }
};
//APPROACH->  // Move slow by 1 step and fast by 2 steps.
              // If they ever meet, there’s a cycle; if fast hits NULL, no cycle.
//TC:O(N),SC:O(1)

//question link: https://leetcode.com/problems/middle-of-the-linked-list/
//QUESTION 2: MIDDLE OF THE LINKED LIST
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
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
};
//APPROACH->// Move slow by 1 step and fast by 2 steps from the head.
            // When fast reaches the end, slow will be at the middle.
//TC:O(N),SC:O(1)
