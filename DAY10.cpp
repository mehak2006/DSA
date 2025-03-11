//Question link:https://leetcode.com/problems/rearrange-array-elements-by-sign/description/
//QUESTION 1: REARRANGE ELEMENTS BY SIGN
//CODE->
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        // TWO POINTER APPROACH
        int pos = 0;
        int neg = 1;
        vector<int>result(nums.size());
        for(int num: nums){
            if(num>0){
                result[pos]=num;
                pos+=2;
            }
            else{
                result[neg]=num;
                neg+=2;
            }
        }
        return result;
    }
};
//APPROACH:Used 2 pointers->pos(for even index), neg(for odd index), created a resultant array, added at pos index if positive, at neg index if negative
//TC: O(N),SC:O(N)

//Question link:https://leetcode.com/problems/next-permutation/description/
//QUESTION 2: NEXT PERMUTATION
//CODE->
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // two pointers
        // Find the first decreasing element from the right, swap it with the
        // next larger element on its right, then reverse the remaining part.
        int n = nums.size();
        int start = n - 1;
        int end = n - 2;
        while (end >= 0 && nums[end] >= nums[end + 1]) {
            end--;
        }
        // end is the first decreasing element from right
        // now we have to find next larger element on the right of end index
        if (end >= 0) {
            while (nums[start] <= nums[end]) {
                start--;
            }

            // swap
            swap(nums[start], nums[end]);
        }
        reverse(nums.begin() + end + 1, nums.end());
    }
};
//APPROACH: Find the first decreasing element from the right, swap it with the next larger element on its right, then reverse the remaining part.
//TC: O(N),SC:O(1)

//Question link:https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
//QUESTION 3: BUY AND SELL STOCK
//CODE->
class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int minPrice = INT_MAX;
     int maxPrice=0;
     for(int i = 0;i<prices.size();i++){
        minPrice= min(minPrice, prices[i]);
        maxPrice= max(maxPrice, prices[i]-minPrice);
     }
     
    return maxPrice;
    }
};
//APPROACH: took two variables->minPrice and maxPrice, ran a loop from i = 0->n, took the minimum of the minPrice and currentElement, then took the maximum of maxPrice and the difference of current element and minPrice, this max difference is the optimal buying selling stock profit 
//TC: O(N),SC:O(1)
