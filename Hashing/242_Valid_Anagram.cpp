/*
Problem: Valid Anagram
Platform: LeetCode (LC 242)
Topic: Hashing / Strings

---------------------------------------------------------

Approach:

- Use frequency array
- Increment for s, decrement for t
- If all values are zero → anagram

---------------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(1)

Example:
Input: s = "anagram", t = "nagaram"
Output: true
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() != t.size()) return false;

        int freq[26] = {0};

        for(int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
            freq[t[i] - 'a']--;
        }

        for(int i = 0; i < 26; i++) {
            if(freq[i] != 0) return false;
        }

        return true;
    }
};
