//Question link: https://leetcode.com/problems/two-sum/description/
//Question 1 : TWO SUM
//CODE->
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> countMap;
        for(int i = 0;i<nums.size();i++){
            int second = target-nums[i];
            if(countMap.count(second)){
                return {countMap[second],i};
            }
            countMap[nums[i]]=i;
        }
        return{};
    }
};
//APPROACH:Use unordered map(hash-table)to store indexes of elements, if a complement was found array of those two were returned
//TC: O(N), SC:O(N)

//Question link: https://leetcode.com/problems/sort-colors/description/
//Question 2 : SORT COLORS
//CODE->
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // HINT: use three pointers->low,mid,high to swap efficiently
        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;
      
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[mid], nums[low]);
                low++;
                mid++;
            } else if (nums[mid] == 1)
                mid++;
            else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
//APPROACH: ->Keep all the 0s before the low pointer all the 2's after the high pointers,and all the 1's between the low and high pointers you move the mid pointer
//TC: O(N), SC:O(1)


//Question link:https://www.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/0
//Question 3 : MAX SUM IN SUBARRAYS
//CODE->

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution {
  public:
    // Function to find pair with maximum sum
        int pairWithMaxSum(vector<int> &arr) {
          
           int maxSum = INT_MIN;

            for (int i = 1; i < arr.size(); i++)
            {
                maxSum = max(maxSum, arr[i] + arr[i - 1]);
            }
        
            return maxSum;
    
    
        }
    };



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        cout << ob.pairWithMaxSum(nums) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
//APPROACH: Since max sum of smallest and second smallest element in any given subarray will always be an adjacent pair, we just check for sum of maximum adjacent pairs
//TC: O(N), SC:O(1)
