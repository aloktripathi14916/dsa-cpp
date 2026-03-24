/*
Problem: Ugly Number
Platform: LeetCode (LC 263)
Topic: Math

An ugly number is a positive integer whose prime factors
are limited to 2, 3, and 5.

Given an integer n, return true if n is an ugly number.

---------------------------------------------------------

Approach: Divide by Allowed Prime Factors

1. If n <= 0 → not ugly
2. Keep dividing n by:
    - 2
    - 3
    - 5
3. If final value becomes 1 → only had allowed factors

---------------------------------------------------------

Time Complexity: O(log n)
Space Complexity: O(1)

Example:
Input: n = 6
Output: true   (6 = 2 × 3)

Input: n = 14
Output: false  (14 = 2 × 7 → 7 not allowed)
*/

class Solution {
public:
    bool isUgly(int n) {

        if(n <= 0) return false;

        // Remove all factors of 2, 3, 5
        while(n % 2 == 0) n /= 2;
        while(n % 3 == 0) n /= 3;
        while(n % 5 == 0) n /= 5;

        return (n == 1);
    }
};
