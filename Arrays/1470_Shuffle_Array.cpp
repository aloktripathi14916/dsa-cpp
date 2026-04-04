/*
Problem: Shuffle the Array
Platform: LeetCode (LC 1470)
Topic: Arrays

---------------------------------------------------------

Approach:

- Given [x1...xn, y1...yn]
- Place:
    ans[2*i]   = xi
    ans[2*i+1] = yi

---------------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(n)

Example:
Input: nums = [2,5,1,3,4,7], n = 3
Output: [2,3,5,4,1,7]
*/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        
        vector<int> ans(2 * n);

        for(int i = 0; i < n; i++) {
            ans[2 * i] = nums[i];
            ans[2 * i + 1] = nums[i + n];
        }

        return ans;
    }
};
