/*
Problem: Longest Repeating Character Replacement
Platform: LeetCode (LC 424)
Topic: Sliding Window

---------------------------------------------------------

Approach:

- Use sliding window with frequency array
- Track most frequent character (maxFreq)
- If replacements needed > k → shrink window

---------------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(1)

Example:
Input: s = "AABABBA", k = 1
Output: 4
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int st = 0;
        int maxLen = 0;
        int maxFreq = 0;

        vector<int> freq(26, 0);

        for(int end = 0; end < s.length(); end++) {

            freq[s[end] - 'A']++;
            maxFreq = max(maxFreq, freq[s[end] - 'A']);

            // shrink if invalid
            if((end - st + 1) - maxFreq > k) {
                freq[s[st] - 'A']--;
                st++;
            }

            maxLen = max(maxLen, end - st + 1);
        }

        return maxLen;
    }
};
