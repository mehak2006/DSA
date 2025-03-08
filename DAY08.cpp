//Question link: https://leetcode.com/problems/move-zeroes/
//QUESTION 1: MOVE ZEROES
//CODE->
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};

//APPROACH: Used two pointer approach, a pointer j for all non zero elements and i traversing through the array
//TC:O(N), SC:O(1)

//Question link: https://leetcode.com/problems/rotate-array/submissions/1567296875/
//QUESTION 2:ROTATE ARRAY
//CODE->
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        k = k % size;  
        
        reverse(nums.begin(), nums.end());  
        reverse(nums.begin(), nums.begin() + k);  
        reverse(nums.begin() + k, nums.end());  
    }
};


//APPROACH: First reversed the array, then reversed till k th element, then reversed the next elements(k+1 to n)
// TC: O(N), SC: O(1)
