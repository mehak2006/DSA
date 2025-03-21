//question link:https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/
//QUESTION 1:MAXIMUM NESTING DEPTH OF PARANTHESES
//CODE->
class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int maxDepth = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                depth++;
                maxDepth = max(maxDepth, depth);
            } else if (s[i] == ')')
                depth--;
        }
        return maxDepth;
    }
};
//APPROACH->Created a counter called depth that increased by when on'(', took maxDepth each time, and then decreased counter if ')'occured. This ensured that maximum consecutive '('was considered before occurence of')'
//TC:O(N),SC:O(1)

//question link:https://leetcode.com/problems/roman-to-integer/description/
//QUESTION 2:ROMAN TO INTEGER
//CODE->
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman = {{'I', 1},   {'V', 5},   {'X', 10},
                                          {'L', 50},  {'C', 100}, {'D', 500},
                                          {'M', 1000}};
        int total = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (i < n - 1 && roman[s[i]] < roman[s[i + 1]]) {
                total -= roman[s[i]]; // Subtract when a smaller numeral appears
                                      // before a larger one
            } else {
                total += roman[s[i]];
            }
        }
        return total;
    }
};
//APPROACH->Created an unordered map/hash table that had roman and resspective integral numbers, read string from left to right, if character was smaller than next one, number was subtracted, otherwise added
//TC:O(N),SC:O(1)
