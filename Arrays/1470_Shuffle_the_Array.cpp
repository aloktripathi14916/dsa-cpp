/*
Problem: Shuffle the Array
Platform: LeetCode (LC 1470)
Topic: Arrays

Given an array nums consisting of 2n elements in the form
[ x1,x2,...,xn,y1,y2,...,yn ], return the array in the form
[ x1,y1,x2,y2,...,xn,yn ].

Approach:
- Create an answer vector of size 2n.
- Iterate from 0 to n-1:
    - Place nums[i] at even indices: ans[2*i]
    - Place nums[i+n] at odd indices: ans[2*i + 1]
- Return the answer vector.

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

        for (int i = 0; i < n; i++) {
            ans[2 * i] = nums[i];       // place x_i
            ans[2 * i + 1] = nums[i + n]; // place y_i
        }

        return ans;
    }
};
