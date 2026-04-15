/*
Problem: Longest Substring Without Repeating Characters
Platform: LeetCode (LC 3)
Topic: Sliding Window / Hashing

---------------------------------------------------------

Approach:

- Use sliding window with a set
- Expand window if no duplicate
- Shrink window if duplicate found

---------------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(n)

Example:
Input: s = "abcabcbb"
Output: 3
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_set<char> st;

        int left = 0, right = 0;
        int maxLen = 0;

        while(right < s.length()) {

            while(st.find(s[right]) != st.end()) {
                st.erase(s[left]);
                left++;
            }

            st.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};
