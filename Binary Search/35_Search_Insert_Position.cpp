/*
Problem: Search Insert Position
Platform: LeetCode (LC 35)
Topic: Binary Search

---------------------------------------------------------

Approach:

- Find the first position where element ≥ target
- If found → return index
- Else → return insertion position

---------------------------------------------------------

Time Complexity: O(log n)
Space Complexity: O(1)

Example:
Input: nums = [1,3,5,6], target = 5
Output: 2

Input: nums = [1,3,5,6], target = 2
Output: 1
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int st = 0, end = nums.size() - 1;

        while(st <= end) {

            int mid = st + (end - st) / 2;

            if(nums[mid] == target) {
                return mid;
            }
            else if(nums[mid] < target) {
                st = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return st; // insertion position
    }
};
