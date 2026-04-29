/*
Problem: Rotate Array
Platform: LeetCode (LC 189)
Topic: Arrays / Reversal Technique

---------------------------------------------------------

Approach:

We rotate the array to the right by k steps using the
reversal algorithm:

1. Reverse the entire array
2. Reverse the first k elements
3. Reverse the remaining n-k elements

This rearranges elements into the required rotated order.

---------------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(1)

Example:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int n = nums.size();
        k = k % n;

        // Step 1: reverse entire array
        reverse(nums.begin(), nums.end());

        // Step 2: reverse first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Step 3: reverse remaining elements
        reverse(nums.begin() + k, nums.end());
    }
};
