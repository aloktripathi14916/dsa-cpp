/*
Problem: Minimum Size Subarray Sum
Platform: LeetCode (LC 209)
Topic: Sliding Window

---------------------------------------------------------

Approach:

Use variable size sliding window.

- Expand the window by moving end and adding nums[end]
- Whenever sum >= target:
    update minimum window size
    shrink from left to try finding a smaller valid window

Since all elements are positive,
this approach works efficiently.

---------------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(1)

Example:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int st = 0;
        int sum = 0;
        int windowsize = INT_MAX;

        for(int end = 0; end < nums.size(); end++) {
            sum += nums[end];

            while(sum >= target) {
                windowsize = min(windowsize, end - st + 1);
                sum -= nums[st];
                st++;
            }
        }

        return windowsize == INT_MAX ? 0 : windowsize;
    }
};
