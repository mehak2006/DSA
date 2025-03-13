//question link: https://leetcode.com/problems/binary-search/description/
//QUESTION 1: SIMPLE BINARY SEARCH
//CODE->
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        // iterative solution
        int low = 0;
        int high = n - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (target == nums[mid])
                return mid;
            else if (target > nums[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }
};
//APPROACH:Simple binary search algorithm, where you divide into and move left or right depending on whether number is greater or lesser tha target(array is sorted)
//TC: O(logN), SC: O(1)

//question link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
//QUESTION 2: FIRST AND LAST POSITION OF ELEMENT
//CODE->
class Solution {
public:
int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}
int upperBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lowerBound(nums,n,target);
        int ub = upperBound(nums,n,target);
        if(lb==n||nums[lb]!=target)return {-1,-1};
        return {lb,ub-1};
    }
};
//APPROACH: First occurence is lowerbound, and last occurence is upperbound-1, lowerbound is founnd by moving leftward if mid may be the answer and otherwise rightwards, upperbound is same just you remove the equal to condition
//TC: O(logN), SC: O(1)

//question link: https://leetcode.com/problems/search-insert-position/
//QUESTION 3: SEARCH INSERT POSITION
//CODE->
class Solution {
public:
    int lowerBound(vector<int> arr, int n, int x) {
        int low = 0, high = n - 1;
        int ans = n;

        while (low <= high) {
            int mid = (low + high) / 2;
            // maybe an answer
            if (arr[mid] >= x) {
                ans = mid;
                // look for smaller index on the left
                high = mid - 1;
            } else {
                low = mid + 1; // look on the right
            }
        }
        return ans;
    }
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        return lowerBound(nums, n, target);
    }
};
//APPROACH: Search insert position is just lowerbound index, lowerbound is founnd by moving leftward if mid may be the answer and otherwise rightwards
//TC: O(logN), SC: O(1)
