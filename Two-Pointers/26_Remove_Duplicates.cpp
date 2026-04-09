/*
Problem: Remove Duplicates from Sorted Array
Platform: LeetCode (LC 26)
Topic: Two Pointers

---------------------------------------------------------

Approach:

- Use two pointers:
    i → iterate through array
    k → position to place next unique element

- When nums[i] != nums[i-1]:
    place element at index k

---------------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(1)

Example:
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if(nums.empty()) return 0;

        int k = 1;

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[i - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};
