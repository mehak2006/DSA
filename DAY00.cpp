//Question 1: https://leetcode.com/problems/concatenation-of-array/description/
//Problem : Concatenation of array
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        nums.insert(nums.end(), nums.begin(), nums.end());
        return nums;
    }
};
//Approach : Merging two lists
//TC:O(N),SC:O(N)

//Question 2:https://leetcode.com/problems/contains-duplicate/description/
//Problem Name: Contain Duplicate
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //APPROACH->using unordered sets; as sets take unique elements only
        unordered_set<int> check;
        for (int i = 0; i < nums.size(); i++){
            check.insert(nums[i]);
        }
        return check.size()<nums.size();
    }
};
//APPROACH-using unordered set, as it takes unique element only,
//TC: O(N),SC: O(N)
