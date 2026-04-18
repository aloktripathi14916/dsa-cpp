/*
Problem: Is Subsequence
Platform: LeetCode (LC 392)
Topic: Two Pointers / Strings

---------------------------------------------------------

Approach:

- Use two pointers:
    i → for string s
    j → for string t

- Traverse t:
    if characters match → move both
    else → move j only

- If all characters of s are matched → true

---------------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(1)

Example:
Input: s = "abc", t = "ahbgdc"
Output: true
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int i = 0, j = 0;

        while(i < s.size() && j < t.size()) {
            if(s[i] == t[j]) {
                i++;
            }
            j++;
        }

        return i == s.size();
    }
};
