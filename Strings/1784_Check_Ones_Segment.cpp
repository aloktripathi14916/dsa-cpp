/*
Problem: Check if Binary String Has at Most One Segment of Ones
Platform: LeetCode (LC 1784)
Topic: Strings

Given a binary string s, return true if it contains
at most one contiguous segment of 1's.

---------------------------------------------------------

Approach:

- Traverse the string.
- If we ever see pattern "01" followed by "1" again → invalid
- Specifically:
    If "0" is followed by "1" → second segment of 1's → return false

---------------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(1)

Example:
Input: "110"
Output: true

Input: "1001"
Output: false
*/

class Solution {
public:
    bool checkOnesSegment(string s) {

        for(int i = 0; i < s.length() - 1; i++) {
            if(s[i] == '0' && s[i + 1] == '1') {
                return false;
            }
        }

        return true;
    }
};
