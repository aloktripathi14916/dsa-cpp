/*
Problem: Find the Difference
Platform: LeetCode (LC 389)
Topic: Bit Manipulation

---------------------------------------------------------

Approach:

- Use XOR operation
- XOR all characters of both strings
- Matching characters cancel out
- Remaining character is the answer

---------------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(1)

Example:
Input: s = "abcd", t = "abcde"
Output: 'e'
*/

class Solution {
public:
    char findTheDifference(string s, string t) {
        
        char res = 0;

        for(char c : s) {
            res ^= c;
        }

        for(char c : t) {
            res ^= c;
        }

        return res;
    }
};
