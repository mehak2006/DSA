//question link: https://www.geeksforgeeks.org/problems/square-root/0?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=square-root
//QUESTION 1:SQUARE ROOT
//CODE->
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Function to find square root
// x: element to find square root
class Solution {
  public:
    int floorSqrt(int n) {
        // Your code goes here
        int low = 1;
        int high = n;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(mid*mid==n)return mid;
            if(mid*mid>n){
                high = mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return high;//ceil
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
//APPROACH->Used binary search, if mid element was the square root returned it, otherwise if higher eliminated the right half, if lower elminated the left half, returned high(as we have to return ceil value)
//TC: O(logN), SC: O(1)

//question link:https://leetcode.com/problems/koko-eating-bananas/
//QUESTION 2: KOKO EATING BANANAS
//CODE->
#include <climits>
#include <vector>
using namespace std;
class Solution {
public:
    long long hours(vector<int>& piles, int k) {
        long long total_hours = 0;
        for (int i = 0; i < piles.size(); i++) {
            total_hours += (piles[i] + k - 1) / k;
        }
        return total_hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long hours_total = hours(piles, mid);
            if (hours_total <= h)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};
//APPROACH->defined a function for calculating total hours, n+k-1/k returns the ceil value of n/k, stored it in long long to avoid overflow, then used simple binary search if total hours were less than or equal to than required, eliminated the right halg otherwise eliminated the left half, then returned low(as we need the smallest divisor)
//TC: O(N*log(maxElement(piles[])), SC: O(1)

//question link:https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/submissions/1576444870/
//QUESTION 3:FIND THE SMALLEST DIVISOR GIVEN A THRESHOLD
//CODE->
#include <climits>
#include <vector>
using namespace std;
class Solution {
public:
    long long sumofDivisors(vector<int>& nums, int k) {
        long long total_sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            total_sum+= (nums[i] + k - 1) / k;
        }
        return total_sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long hours_sum = sumofDivisors(nums, mid);
            if (hours_sum <= threshold)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};
//APPROACH-> basically the same question as Q2
//TC: O(O(N*log(maxElement(nums[])), SC: O(1)
