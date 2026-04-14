/*
Problem: Power of Three
Platform: LeetCode (LC 326)
Topic: Recursion / Math

---------------------------------------------------------

Approach:

- Recursively divide number by 3
- If we reach 1 → true
- If not divisible by 3 or <= 0 → false

---------------------------------------------------------

Time Complexity: O(log n)
Space Complexity: O(log n)

Example:
Input: n = 27
Output: true
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        
        if(n <= 0) return false;
        if(n == 1) return true;

        if(n % 3 != 0) return false;

        return isPowerOfThree(n / 3);
    }
};
