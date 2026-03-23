/*
Problem: String Compression
Platform: LeetCode (LC 443)
Topic: Strings / Two Pointer

Given an array of characters, compress it in-place such that:
- For each group of consecutive repeating characters:
    - Write the character followed by the count (if > 1)

Return the new length of the compressed array.

---------------------------------------------------------

Approach: Two Pointer + Count

1. Traverse the array and count consecutive characters.
2. Write the character to the result index.
3. If count > 1, convert count to string and append digits.
4. Continue until the end.

Time Complexity: O(n)
Space Complexity: O(1) (in-place)

Example:
Input: ["a","a","b","b","c","c","c"]
Output: ["a","2","b","2","c","3"], return 6
*/

class Solution {
public:
    int compress(vector<char>& str) {

        int n = str.size();
        int idx = 0;   // position to write compressed output

        for(int i = 0; i < n; i++) {

            char ch = str[i];
            int count = 0;

            // Count occurrences of current character
            while(i < n && str[i] == ch) {
                count++;
                i++;
            }

            // Write character
            str[idx++] = ch;

            // Write count if > 1
            if(count > 1) {
                string ct = to_string(count);
                for(char digit : ct) {
                    str[idx++] = digit;
                }
            }

            i--; // adjust for outer loop increment
        }

        return idx;
    }
};
