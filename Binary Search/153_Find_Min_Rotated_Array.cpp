/*
Problem: Find Minimum in Rotated Sorted Array
Platform: LeetCode (LC 153)
Topic: Binary Search

---------------------------------------------------------

Approach:

- In a rotated sorted array, compare mid with end
- If nums[mid] > nums[end]:
      minimum lies on right side
- Else:
      minimum lies at mid or on left side

Keep shrinking until st == end.

---------------------------------------------------------

Time Complexity: O(log n)
Space Complexity: O(1)

Example:
Input: [4,5,6,7,0,1,2]
Output: 0
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int st = 0, end = nums.size() - 1;

        while(st < end) {
            int mid = st + (end - st) / 2;

            if(nums[mid] > nums[end])
                st = mid + 1;
            else
                end = mid;
        }

        return nums[st];
    }
};
