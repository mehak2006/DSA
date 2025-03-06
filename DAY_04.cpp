//Question link: https://leetcode.com/problems/count-distinct-numbers-on-board/description/?envType=problem-list-v2&envId=math
//QUESTION 1: COUNT DISTINCT NUMBERS ON BOARD
//CODE->
class Solution {
public:
    int distinctIntegers(int n) {
        if(n==1)return 1;
        return n-1;
    }
};
//APPROACH: Eventually, all numbers from 2 to n will appear on the board if n > 1. If n == 1, the only number on the board remains 1.
//TC:O(1), SC:O(1)

//Question link: https://www.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
//QUESTION 2: CHOCOLATE DISTRIBUTION PROBLEM
//CODE->
class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        //subarray of length m
        int minimum = INT_MAX;
        sort(a.begin(), a.end());
        for(int i = 0;i+m-1<a.size();i++){
          
                if(minimum> a[i+m-1]-a[i])minimum= a[i+m-1]-a[i];
            
        }
        return minimum;
    }
};
//APPROACH: First sorted the array,  tehn took subarrays of size m, compared the differences and returned the minimum one
//TC: O(N logN), SC: O(1)
