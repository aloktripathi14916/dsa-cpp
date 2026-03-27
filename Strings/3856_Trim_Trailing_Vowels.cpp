/*
Problem: Trim Trailing Vowels
Platform: LeetCode (LC 3856)
Topic: Strings

Given a string s, remove all trailing vowels
('a', 'e', 'i', 'o', 'u') from the end of the string.

---------------------------------------------------------

Approach:

1. Start from the end of the string.
2. While the current character is a vowel:
    - Remove it using pop_back()
3. Stop when a non-vowel is found.

---------------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(1)

Example:
Input: "helloo"
Output: "hell"

Input: "leetcode"
Output: "leetcod"
*/

class Solution {
public:
    bool isVowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' ||
               ch == 'o' || ch == 'u';
    }

    string trimTrailingVowels(string s) {

        while(!s.empty() && isVowel(s.back())) {
            s.pop_back();
        }

        return s;
    }
};
