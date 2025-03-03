//Question link: https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/submissions/1561531058/
//Approach
//-> First checked for each element in the first array and the second array, if the key was same, added the value, then marked that element in second array as merged, then for elements left in second array added the unmerged elements
//Time complexity: O(NlogN), Space Complexity:O(N)
//MERGE TWO 2D ARRAYS BY SUMMING VALUES
class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        // Merge values for common elements
        for (int i = 0; i < nums1.size(); i++) {
            for (int k = 0; k < nums2.size(); k++) {
                if (nums1[i][0] == nums2[k][0]) {
                    nums1[i][1] += nums2[k][1];
                    nums2[k][0] = -1; // Mark as merged
                }
            }
        }

        // Add elements from nums2 that were not merged
        for (int k = 0; k < nums2.size(); k++) {
            if (nums2[k][0] != -1) {
                nums1.push_back({nums2[k][0], nums2[k][1]});
            }
        }

        // Sort the final array
        sort(nums1.begin(), nums1.end());

        return nums1;
    }
};
//Question link: https://www.geeksforgeeks.org/problems/good-or-bad-string1417/1
//Approach
//-> First checked for whether consecutive vowels and consonants, when they are not consecutive, count is reset, then added final check for edge cases, for e.g., when vowel count does not exceed 5 like aaaaa
//Time complexity: O(N), Space Complexity:O(1)
//CHECK GOOD STRING OR BAD STRING
//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int isGoodorBad(string S) {
        int vow_count=0;
        int cons_count=0;
        
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='a' || S[i]=='e' || S[i]=='i' || S[i]=='o' || S[i]=='u')
            {
                vow_count++;
                cons_count=0;
                if(vow_count>5)
                {
                    return 0;
                }
            }
            else if(S[i]=='?')
            {
                vow_count++;
                cons_count++;
                if(vow_count>5 || cons_count>3)
                {
                    return 0;
                }
            }
            else
            {
                vow_count=0;
                cons_count++;
                if(cons_count>3)
                {
                    return 0;
                }
            }
           
        }
        if(vow_count>5 || cons_count>3)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        
        cin >> S;
        
        Solution ob;
        cout << ob.isGoodorBad(S) << endl;
    
cout << "~" << "\n";
}
    return 0; 
}
// } Driver Code Ends
