/*
Problem: Power of Two
Platform: LeetCode (LC 231)
Topic: Bit Manipulation

Given an integer n, return true if it is a power of two.
Otherwise, return false.

An integer n is a power of two if there exists an integer x such that:
    n = 2^x

---------------------------------------------------------

Approach: Bit Manipulation Trick

Key Idea:
- A power of two has only ONE set bit in binary.

Example:
1  -> 0001
2  -> 0010
4  -> 0100
8  -> 1000

- For such numbers:
    n & (n - 1) == 0

Why?
- n       = 1000
- n - 1   = 0111
- AND     = 0000

---------------------------------------------------------

Time Complexity: O(1)
Space Complexity: O(1)

Example:
Input: n = 16
Output: true

Input: n = 18
Output: false
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {

        // n must be positive and have only one set bit
        return (n > 0 && (n & (n - 1)) == 0);
    }
};
