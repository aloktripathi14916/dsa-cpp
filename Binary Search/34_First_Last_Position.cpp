/*
Problem: Find First and Last Position of Element in Sorted Array
Platform: LeetCode (LC 34)
Topic: Binary Search

---------------------------------------------------------

Approach:

Perform two binary searches:

1. Find first occurrence:
   - when target found, continue searching left

2. Find last occurrence:
   - when target found, continue searching right

---------------------------------------------------------

Time Complexity: O(log n)
Space Complexity: O(1)

Example:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();
        int first = -1, last = -1;

        int st = 0, end = n - 1;

        // find last occurrence
        while(st <= end) {
            int mid = st + (end - st) / 2;

            if(nums[mid] == target) {
                last = mid;
                st = mid + 1;
            }
            else if(nums[mid] > target) {
                end = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }

        st = 0;
        end = n - 1;

        // find first occurrence
        while(st <= end) {
            int mid = st + (end - st) / 2;

            if(nums[mid] == target) {
                first = mid;
                end = mid - 1;
            }
            else if(nums[mid] > target) {
                end = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }

        return {first, last};
    }
};
