/*
Problem: Remove All Occurrences of a Substring
Platform: LeetCode (LC 1910)
Topic: Strings

Given two strings `str` and `t`, repeatedly remove all occurrences of `t` from `str` until `t` no longer occurs in `str`. Return the final string.

---------------------------------------------------------

Approach: Iterative find + erase

1. While `t` is found in `str`:
    - Find starting index of `t` in `str`
    - Erase substring of length `t.size()` from that index
2. Repeat until `t` is no longer in `str`

Time Complexity: O(n * m) worst case (n = str.length(), m = t.length())  
Space Complexity: O(1) (in-place)

Example:
Input: str = "axxxxyyyyb", t = "xy"
Output: "ab"

Input: str = "aabab", t = "ab"
Output: "a"
*/

class Solution {
public:
    string removeOccurrences(string str, string t) {

        while(str.find(t) != string::npos) {
            int begin = str.find(t);
            str.erase(begin, t.size());
        }

        return str;
    }
};
