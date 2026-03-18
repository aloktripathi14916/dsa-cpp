/*
Problem: Search in Rotated Sorted Array
Platform: LeetCode (LC 33)
Topic: Arrays / Binary Search

You are given a sorted array that has been rotated at some pivot.
Find the index of target element. If not found, return -1.

---------------------------------------------------------

Approach: Modified Binary Search

Key Idea:
- At least one half (left or right) is always sorted.
- Check which half is sorted:
    - If left half is sorted:
        → Check if target lies in this range.
    - Else right half is sorted:
        → Check if target lies in this range.
- Narrow down search space accordingly.

Time Complexity: O(log n)
Space Complexity: O(1)

Example:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int st = 0, end = nums.size() - 1;

        while (st <= end) {

            int mid = st + (end - st) / 2;

            if (nums[mid] == target)
                return mid;

            // Left half is sorted
            if (nums[st] <= nums[mid]) {

                if (target >= nums[st] && target < nums[mid])
                    end = mid - 1;
                else
                    st = mid + 1;
            }

            // Right half is sorted
            else {

                if (target > nums[mid] && target <= nums[end])
                    st = mid + 1;
                else
                    end = mid - 1;
            }
        }

        return -1;
    }
};
