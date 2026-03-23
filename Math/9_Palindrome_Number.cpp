/*
Problem: Palindrome Number
Platform: LeetCode (LC 9)
Topic: Math / Strings

Given an integer x, return true if x is a palindrome,
and false otherwise.

---------------------------------------------------------

Approach 1: Convert to String (Your Approach)

- Extract digits and build a string.
- Reverse the string.
- Compare original and reversed.

Time Complexity: O(n)
Space Complexity: O(n)

---------------------------------------------------------

Approach 2: Reverse Half Number (Optimal)

Key Idea:
- Reverse only half of the number.
- Compare first half with reversed second half.
- Avoid string conversion.

Time Complexity: O(log n)
Space Complexity: O(1)

Example:
Input: x = 121
Output: true

Input: x = -121
Output: false
*/

class Solution {
public:

    // ----------- Approach 1: String Method -----------
    bool isPalindromeString(int x) {

        if(x < 0) return false;

        string num = to_string(x);
        string rev = num;

        reverse(rev.begin(), rev.end());

        return num == rev;
    }


    // ----------- Approach 2: Optimal (Reverse Half) -----------
    bool isPalindrome(int x) {

        // Negative numbers & numbers ending with 0 (except 0 itself)
        if(x < 0 || (x % 10 == 0 && x != 0))
            return false;

        int revHalf = 0;

        while(x > revHalf) {
            int digit = x % 10;
            revHalf = revHalf * 10 + digit;
            x /= 10;
        }

        // For even digits: x == revHalf
        // For odd digits: x == revHalf / 10
        return (x == revHalf || x == revHalf / 10);
    }
};
