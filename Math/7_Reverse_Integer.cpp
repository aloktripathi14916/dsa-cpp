/*
Problem: Reverse Integer
Platform: LeetCode (LC 7)
Topic: Math

Given a signed 32-bit integer x, return x with its digits reversed.
If reversing x causes the value to go outside the signed 32-bit range
[-2^31, 2^31 - 1], then return 0.

---------------------------------------------------------

Approach:

1. Extract digits using modulo (% 10)
2. Build reversed number step by step
3. Before adding a digit, check for overflow

---------------------------------------------------------

Overflow Check:

Before:
    reverse = reverse * 10 + digit

Check:
    if(reverse > INT_MAX/10 || reverse < INT_MIN/10)
        return 0;

---------------------------------------------------------

Time Complexity: O(log n)
Space Complexity: O(1)

Example:
Input: x = 123
Output: 321

Input: x = -123
Output: -321

Input: x = 1534236469
Output: 0 (overflow)
*/

class Solution {
public:
    int reverse(int x) {

        int rev = 0;

        while(x != 0) {

            int digit = x % 10;
            x /= 10;

            // Check for overflow before multiplying
            if(rev > INT_MAX / 10 || rev < INT_MIN / 10)
                return 0;

            rev = rev * 10 + digit;
        }

        return rev;
    }
};
