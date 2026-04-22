/*
Problem: Find the Index of the First Occurrence in a String
Platform: LeetCode (LC 28)
Topic: Strings / Brute Force

---------------------------------------------------------

Approach:

- Iterate through all possible starting indices
- Compare substring of length m with needle

---------------------------------------------------------

Time Complexity: O(n * m)
Space Complexity: O(1)
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int n = haystack.size();
        int m = needle.size();

        for(int i = 0; i <= n - m; i++) {

            if(haystack.substr(i, m) == needle)
                return i;
        }

        return -1;
    }
};
