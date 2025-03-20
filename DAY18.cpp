//STRINGS
//question link:https://leetcode.com/problems/valid-anagram/
//QUESTION 1: VALID ANAGRAM
//CODE->
class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t)return true;
        return false;
    }
};
//APPROACH->Sorted both strings lexicographically, then compared. To reduce TC, we can use hash table/unordered_map
//TC: O(NlogN), SC: O(1)

//question link:https://leetcode.com/problems/longest-common-prefix/
//QUESTION 2:LONGEST COMMON PREFIX
//CODE->
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // check for consecutive characters
        int n = strs.size();
        string ans = "";
        //
        sort(strs.begin(), strs.end()); // this sorts the array like a
                                        // dictionary, i.e. lexicographically
        // so now we just have to compare for first and last word
        for (int i = 0; i < min(strs[0].size(), strs[n - 1].size()); i++) {
            if (strs[0][i] != strs[n - 1][i]) {
                return ans;
            }
            ans += strs[0][i];
        }
        return ans;
    }
};
//APPROACH->Sorted the array lexicographically, then checked longest prefix for first and last string till first string's length
//TC: O(NlogN), SC: O(M)
