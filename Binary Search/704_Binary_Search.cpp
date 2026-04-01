/*
Problem: Binary Search
Platform: LeetCode (LC 704)
Topic: Binary Search

---------------------------------------------------------

Approach:

- Classic binary search on sorted array
- Compare middle element with target
- Narrow down search space accordingly

---------------------------------------------------------

Time Complexity: O(log n)
Space Complexity: O(1)

Example:
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {

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

        return -1;
    }
};
