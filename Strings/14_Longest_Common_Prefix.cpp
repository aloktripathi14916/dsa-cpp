/*
Problem: Longest Common Prefix
Platform: LeetCode (LC 14)
Topic: Strings

---------------------------------------------------------

Approach:

- Take the first string as reference
- For every character position i:
    compare strs[0][i] with all other strings
- If mismatch found or any string ends:
    return prefix till i

---------------------------------------------------------

Time Complexity: O(n * m)
n = number of strings
m = length of common prefix checked

Space Complexity: O(1)

Example:
Input: ["flower","flow","flight"]
Output: "fl"
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        for(int i = 0; i < strs[0].size(); i++) {
            for(int j = 1; j < strs.size(); j++) {
                if(i >= strs[j].size() || strs[j][i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }

        return strs[0];
    }
};
