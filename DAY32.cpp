//question link: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
//QUESTION 1:REMOVE DUPLICATES FROM SORTED LIST
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr)return nullptr;
        ListNode* dummy = new ListNode(0);
        dummy->next=head;
        ListNode* prev = dummy;//two pointers, where prev points to previous of  temp
        ListNode* temp = head;
        while(temp!=nullptr && temp->next!=nullptr){
            if(temp->val==temp->next->val){
                int v = temp->val;//we have to store it somewhere in case there are 3 consecutive same elements
                while(temp!=nullptr){
                    if(temp->val==v)temp=temp->next;
                    else break;
                }
                prev->next=temp;
            }
            else{
                prev = temp;
                temp=temp->next;
            
            }
        }

        return dummy->next;
    }
};
//APPROACH->We use a dummy node to simplify edge cases where duplicates start at the head, and initialize two pointers: prev (last confirmed unique node) and temp (current scanner).
            //If consecutive nodes have the same value (temp->val == temp->next->val), we record the duplicate value and skip all nodes with that value using a while loop.
            //Once all duplicates are skipped, we connect prev->next to temp, thus removing all instances of the duplicate value from the list.
            //If no duplicate is found, we move both pointers forward normally. Finally, return dummy->next as the new head.

//TC:O(N),SC:O(1)


//question link:  https://leetcode.com/problems/reverse-nodes-in-k-group/description/ 
//QUESTION 2: REVERSE NODES IN K GROUP
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        //first count the number of nodes
        ListNode* temp = head;
        int count = 0;
        while(temp!=nullptr&& count<k){
            temp=temp->next;
            count++;
        }//count stops after k nodes
       
        if(count==k){
            //reverse k elements group
             int i = 0;
            ListNode* prev = nullptr;
            ListNode* current = head;
            ListNode* next = nullptr;
            while(i<k && current!=nullptr){
                next = current->next;
                current->next=prev;
                prev=current;
                current=next;
                i++;
            }
            //now we'll use recursion to reverse next 'k' elements
            if(next!=nullptr){
               head->next = reverseKGroup(next, k);
            }
            return prev;//prev is updated head
        }
        return head;//if fewer than k nodes return as it is
        
    }
};
//APPROACH->Count k nodes ahead—if there are fewer than k, return the head as is (no reversal).
            //If k nodes are found, reverse them iteratively using standard three-pointer technique (prev, current, next).
            //After reversing, the original head (now tail) should connect to the result of the recursive call for the next k-group.
            //Return prev (which is the new head of the reversed group), completing the connection recursively.
//TC:O(N), SC:O(1)
