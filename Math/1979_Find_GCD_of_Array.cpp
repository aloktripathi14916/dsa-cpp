/*
Problem: Find Greatest Common Divisor of Array
Platform: LeetCode (LC 1979)
Topic: Math / GCD

Given an integer array nums, return the greatest common divisor (GCD)
of the smallest and largest numbers in nums.

---------------------------------------------------------

Approach:

1. Find minimum and maximum element in the array.
2. Compute GCD(min, max) using Euclidean Algorithm.

---------------------------------------------------------

Euclidean Algorithm:
gcd(a, b) = gcd(b, a % b)

---------------------------------------------------------

Time Complexity: O(n + log(min, max))
Space Complexity: O(1)

Example:
Input: nums = [2,5,6,9,10]
Output: 2
Explanation:
min = 2, max = 10 → gcd(2,10) = 2
*/

class Solution {
public:
    int findGCD(vector<int>& nums) {

        int mn = INT_MAX;
        int mx = INT_MIN;

        // Find min and max
        for(int num : nums) {
            mn = min(mn, num);
            mx = max(mx, num);
        }

        // Euclidean Algorithm
        while(mn != 0) {
            int r = mx % mn;
            mx = mn;
            mn = r;
        }

        return mx;
    }
};
