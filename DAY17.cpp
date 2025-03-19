//question link:https://leetcode.com/problems/isomorphic-strings/submissions/1579216587/
//QUESTION 1: ISOMORPHIC STRINGS
//CODE->
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // use hash table
        if (s.length() != t.length())
            return false;
        unordered_map<char, char> sTot, tTos;
        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i];
            char c2 = t[i];
            if (sTot.count(c1) && sTot[c1] != c2)
                return false; // this checks if previously mapped element has
                              // been now replaced by wrong element, like if
                              // earlier we mapped a->c and now a->d, then it is
                              // false
            if (tTos.count(c2) && tTos[c2] != c1)
                return false;
            sTot[c1] = c2;
            tTos[c2] = c1;
        }
        return true;
    }
};

//APPROACH->Used unordered map(hash table) to check if previously mapped element was now replaced by another element, basically we have to check for one to one mappinf from S to T, and T to S
//TC: O(N), SC: O(N)

//question link:https://leetcode.com/problems/remove-outermost-parentheses/
//QUESTION 2:REMOVE OUTERMOST PARENTHESES
//CODE->
class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        string result = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                count++;
                if (count > 1)
                    result += s[i]; // not the outermost opening
            } else if (s[i] == ')') {
                count--;
                if (count > 0)
                    result += s[i]; // not the outermost closing
            }
        }
        return result;
    }
};
//APPROACH->used a counter to track the outermost opening and closing tags, if count >0 it is not outermost closing, and if count>1, it is not outermost opening bracket
//TC: O(N), SC: O(N)
