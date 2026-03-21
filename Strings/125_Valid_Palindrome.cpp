/*
Problem: Valid Palindrome
Platform: LeetCode (LC 125)
Topic: Strings / Two Pointer

Given a string, determine if it is a palindrome, considering only
alphanumeric characters and ignoring cases.

---------------------------------------------------------

Approach: Two Pointers + Validation

1. Use two pointers: `st` at start, `end` at end.
2. Skip non-alphanumeric characters.
3. Compare characters in lowercase.
4. If mismatch → not palindrome
5. If pointers cross → valid palindrome

Time Complexity: O(n)
Space Complexity: O(1) (in-place)

Example:
Input: "A man, a plan, a canal: Panama"
Output: true

Input: "race a car"
Output: false
*/

class Solution {
public:

    // Helper function: check if character is alphanumeric
    bool isValid(char ch) {
        return (ch >= '0' && ch <= '9') ||
               (ch >= 'a' && ch <= 'z') ||
               (ch >= 'A' && ch <= 'Z');
    }

    bool isPalindrome(string s) {

        int st = 0, end = s.size() - 1;

        while(st < end) {

            if(!isValid(s[st])) {
                st++;
                continue;
            }

            if(!isValid(s[end])) {
                end--;
                continue;
            }

            if(tolower(s[st]) != tolower(s[end])) {
                return false;
            }

            st++;
            end--;
        }

        return true;
    }
};
