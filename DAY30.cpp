//question link: https://leetcode.com/problems/sort-list/
//QUESTION 1: SORT LIST
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
    ListNode* sortMerge(ListNode* a, ListNode* b) {
        if (a == nullptr)
            return b;
        if (b == nullptr)
            return a;
        ListNode* result = nullptr;
        if (a->val <= b->val) {
            result = a;
            result->next = sortMerge(a->next, b);
        } else {
            result = b;
            result->next = sortMerge(a, b->next);
        }
        return result;
    }

    ListNode* getMiddle(ListNode* head) {
        if (head == nullptr)
            return head;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        // since O(NlogN)complexity is required, mergeSort is required
        ListNode* start = head;
        ListNode* middle = getMiddle(head);
        ListNode* nextofmiddle = middle->next;
        middle->next = nullptr;
        ListNode* left = sortList(head);
        ListNode* right = sortList(nextofmiddle);
        ListNode* result = sortMerge(left, right);
        return result;
    }
};

//APPROACH->Recursively split the linked list into halves until each sublist has one node (using the fast & slow pointer technique to find the middle). Merge the sorted halves using a helper function that merges two sorted linked lists.
//TC:O(NlogN),SC:O(logN)


//question link:https://leetcode.com/problems/remove-nth-node-from-end-of-list/
//QUESTION 2: REMOVE NTH NODE FROM END OF LIST
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next=head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

        for(int i = 0;i<=n;i++){
            fast=fast->next;
        }
        while(fast!=nullptr){
            fast=fast->next;
            slow=slow->next;
        }
        //now slow is before the node to be deleted

        ListNode* toDelete = slow->next;
        slow->next=toDelete->next;
        delete toDelete;
        return dummy->next;//i.e. head
    }
};
//APPROACH->Use two pointers->fast and slow.Move fast pointer n steps ahead. Move both fast and slow until fast reaches the end.Slow will be just before the node to delete.
//TC:O(L),SC:O(1)
