/*
Problem: Reverse Words in a String
Platform: LeetCode (LC 151)
Topic: Strings

Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters.
Return a string of the words in reverse order.

Note:
- Remove extra spaces.
- Only one space between words in output.

---------------------------------------------------------

Approach:

1. Reverse the entire string.
2. Traverse and extract each word.
3. Reverse each word individually.
4. Append to result with a single space.

---------------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(n)

Example:
Input: "the sky is blue"
Output: "blue is sky the"

Input: "  hello world  "
Output: "world hello"
*/

class Solution {
public:
    string reverseWords(string str) {

        int n = str.length();
        string ans = "";

        // Step 1: Reverse entire string
        reverse(str.begin(), str.end());

        for(int i = 0; i < n; i++) {

            string word = "";

            // Extract word
            while(i < n && str[i] != ' ') {
                word += str[i];
                i++;
            }

            // Reverse the word back
            reverse(word.begin(), word.end());

            // Add to result
            if(word.length() > 0) {
                ans += " " + word;
            }
        }

        // Remove leading space
        return ans.substr(1);
    }
};
