/*
Problem: Fibonacci Number
Platform: LeetCode (LC 509)
Topic: Recursion

---------------------------------------------------------

Approach:

- Base cases:
    fib(0) = 0
    fib(1) = 1

- Recursive relation:
    fib(n) = fib(n-1) + fib(n-2)

---------------------------------------------------------

Time Complexity: O(2^n)
Space Complexity: O(n)  (recursion stack)

Example:
Input: n = 4
Output: 3
*/

class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;

        return fib(n - 1) + fib(n - 2);
    }
};
