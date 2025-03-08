//Question link: https://leetcode.com/problems/can-place-flowers/?envType=problem-list-v2&envId=greedy
//QUESTION 1: CAN PLACE FLOWERS
//CODE->
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int count = 0;
        if (flowerbed.size() == 1) {
            if (n == 1 && flowerbed[0] == 0)
                return true;
            if (n == 0)
                return true;
            else
                return false;
        }
        if (flowerbed[0] == 0 && flowerbed[1] == 0) {
            count++;
            flowerbed[0] = 1;
        }
        if (flowerbed[flowerbed.size() - 1] == 0 &&
            flowerbed[flowerbed.size() - 2] == 0) {
            count++;
            flowerbed[flowerbed.size() - 1] = 1;
        }
        for (int i = 1; i <= flowerbed.size() - 2; i++) {
            if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0 &&
                flowerbed[i] == 0) {
                count++;
                flowerbed[i] = 1;
            }
        }
        if (count >= n)
            return true;
        else
            return false;
    }
};

//APPROACH: Here only three pair of adjacent zeroes can give one plant. Edge cases are at starting and end,  and if size = 1. Once counting is done, we also mark spot as 1 to prveent double checking
//TC:O(N), SC:O(1)

//Question link: https://leetcode.com/problems/minimum-positive-sum-subarray/?envType=problem-list-v2&envId=prefix-sum
//QUESTION 2: MINIMUM POSITIVE SUBARRAY SUM
//CODE->
class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int minimum = INT_MAX; // Stores the minimum positive sum found

        for (int i = min(l, r); i <= max(l, r); i++) {
            int sum = 0;

            // Compute the sum of the first window of size 'i'
            for (int j = 0; j < i; j++) {
                sum += nums[j];
            }

            int minSum;
            if (sum > 0) {
                minSum = sum;
            } else {
                minSum = INT_MAX;
            }

            // Sliding window technique
            for (int k = i; k < nums.size(); k++) {
                sum = sum - nums[k - i] + nums[k]; // Slide the window

                if (sum > 0) {
                    minSum = min(minSum, sum);
                }
            }

            if (minSum != INT_MAX) {
                minimum = min(minimum, minSum);
            }
        }

        if (minimum == INT_MAX) {
            return -1;
        } else {
            return minimum;
        }
    }
};

//APPROACH: used sliding window approach to calculate sum, and then used minSum to find minimum of subarrays of size 'i', then used minimum to find minimum from the minSums
// TC: O(N* (R-L+1)), SC: O(1)
