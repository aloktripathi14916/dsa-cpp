/*
Problem: Length of Last Word
Platform: LeetCode (LC 58)
Topic: Strings

---------------------------------------------------------

Approach:

- Traverse string from end
- Skip trailing spaces
- Count characters until space encountered

---------------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(1)

Example:
Input: "Hello World"
Output: 5
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int i = s.length() - 1;

        // skip trailing spaces
        while(i >= 0 && s[i] == ' ') i--;

        int count = 0;

        // count last word
        while(i >= 0 && s[i] != ' ') {
            count++;
            i--;
        }

        return count;
    }
};
