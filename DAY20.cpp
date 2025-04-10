//question link: https://leetcode.com/problems/sort-characters-by-frequency/description/
//QUESTION 1: SORT CHARACTERS BY FREQUENCY
//CODE->
class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Count frequency of each character
        unordered_map<char, int> freq;
        for (char c : s)
            freq[c]++;

        // Step 2: Sort characters in decreasing order of frequency
        sort(s.begin(), s.end(), [&](char a, char b) {
            // If frequencies differ, sort by higher frequency
            if (freq[a] != freq[b])
                return freq[a] > freq[b];
            return a < b;

            /*
            Note: If we skip the second condition (a < b), characters with
            the same frequency may not appear grouped together.

            Example:
            Input: "elololo"
            Frequencies: e=1, l=3, o=3

            Without the second condition,invalid output: "lololoe"
            */
        });

        return s;
    }
};

//APPROACH->
              //Use a hash map (unordered_map) to count the frequency of each character in the string.
              //Sort the string using a custom comparator that orders characters based on their frequency (higher frequency first). Return the sorted string.


//TC:O(NlogN) for sorting,SC:O(N) for frequency

//question link:  https://leetcode.com/problems/string-to-integer-atoi/description/
//QUESTION 2: string to integer ATOI
//CODE->
class Solution {
public:
    int myAtoi(string s) {
        // PROBLEM 1->ignore any leading whitespace
        int i = 0;
        while (i < s.size() && s[i] == ' ') {
            i++;
        }
        // now i points to non-space element

        // PROBLEM 2->to determine sign by checking current char
        int sign = 1; // assume positive, as result will be positive if neither
                      // sign is present
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                sign = -1;
            i++; // move to the next char
        }
        // cannot make this into a loop, because it won't work for cases like ->
        // +-12

        // PROBLEM 3->Read digits until non digit, if no digits were read, reult
        // is 0
        long result = 0; // to handle overflow, underflow as we have a separate
                         // condition for them
        while (i < s.size() && isdigit(s[i])) {
            // create an integer from a string
            // this condition is checked before only because even multiplying sign* result can cause an overflow issue
            if (result > (INT_MAX - (s[i] - '0')) / 10) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            result = result * 10 + (s[i] - '0');
            i++;
        }
        // Now, our result is almost ready

        // PROBLEM 4->handle overflow and underflow cases
        // CLAMPING
        // done in PROBLEM 3

        // Return integer as final result
        return sign * result;
    }
};
//TC:O(N), SC:O(1)
//APPROACH->//We first skip leading whitespaces, then determine the sign (+ or -), and read the digits until a non-digit character is found.   
            //While converting the number, we check for overflow before each update using the condition:
                  //result > (INT_MAX - digit) / 10. This ensures we clamp safely to INT_MAX or INT_MIN if needed.
//TC:O(N),SC:O(1)
