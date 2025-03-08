//Question link: https://leetcode.com/problems/distribute-money-to-maximum-children/description/?envType=problem-list-v2&envId=math
//QUESTION 1: DISTRIBUTE MONEY TO MAXIMUM CHILDREN
//CODE->
class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children)
            return -1; // Not enough money to give at least $1 to each child

        money -= children; // Give each child $1 first
        if (money / 7 == children && money % 7 == 0)//if we can distribute it equally
            return children;
        if (money / 7 == children - 1 && money % 7 == 3)
            return children - 2;
        return min(children - 1, money / 7);
    }
};
//APPROACH:
//TC:O(1), SC:O(1)

//Question link: https://leetcode.com/problems/longest-palindrome/description/?envType=problem-list-v2&envId=greedy
//QUESTION 2: LONGEST PALINDROME
//CODE->
class Solution {
public:
    int longestPalindrome(string s) {
        
        unordered_map<char, int> countMap;
        for (char ch : s) {
            countMap[ch]++; // update frequency count
        }
        int maxLength = 0;
        bool hasOdd = false;
        for (auto& [ch, freq] : countMap) {
            if (freq % 2 == 0)
                maxLength = maxLength + freq;
            else {
                maxLength = maxLength + freq - 1;
                hasOdd = true;
            }
        }
        if (hasOdd == true)
            maxLength++;
        return maxLength;
    }
};
//APPROACH: // we create a hash table using unordered map, possible cases where we can have palindrome-> all elements frequency = even, or all elements frequency = even except one so if there are even elements add fully, if there are odd add even amount frequency -1 except one whose frequency is odd then return longest possible palindrome
// TC: O(N), SC: O(N)
