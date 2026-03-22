/*
Problem: Permutation in String
Platform: LeetCode (LC 567)
Topic: Strings / Sliding Window

Given two strings s1 and s2, return true if s2 contains
a permutation of s1.

---------------------------------------------------------

Approach 1: Brute Force (Your Approach)

- Generate all substrings of size = s1.length()
- Compare frequency of each substring with s1
- If match found → return true

Time Complexity: O(n * 26 * k)
Space Complexity: O(1)

---------------------------------------------------------

Approach 2: Sliding Window (Optimal)

- Maintain a window of size = s1.length()
- Use two frequency arrays:
    - freq1 → for s1
    - freq2 → for current window in s2
- Slide window by:
    - Add new character
    - Remove old character
- Compare frequency arrays

Time Complexity: O(n * 26) ≈ O(n)
Space Complexity: O(1)

Example:
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
*/

class Solution {
public:

    // Helper: compare two frequency arrays
    bool isFreqSame(int freq1[], int freq2[]) {
        for(int i = 0; i < 26; i++) {
            if(freq1[i] != freq2[i])
                return false;
        }
        return true;
    }

    // ----------- Brute Force Approach -----------
    bool checkInclusionBrute(string s1, string s2) {

        int freq[26] = {0};
        for(char c : s1)
            freq[c - 'a']++;

        int windowSize = s1.length();

        for(int i = 0; i < s2.length(); i++) {

            int window[26] = {0};
            int idx = i, count = 0;

            while(count < windowSize && idx < s2.length()) {
                window[s2[idx] - 'a']++;
                idx++;
                count++;
            }

            if(isFreqSame(freq, window))
                return true;
        }

        return false;
    }


    // ----------- Optimal Sliding Window -----------
    bool checkInclusion(string s1, string s2) {

        int n = s2.length();
        int k = s1.length();

        if(k > n) return false;

        int freq1[26] = {0}, freq2[26] = {0};

        for(char c : s1)
            freq1[c - 'a']++;

        // initial window
        for(int i = 0; i < k; i++)
            freq2[s2[i] - 'a']++;

        if(isFreqSame(freq1, freq2))
            return true;

        // sliding window
        for(int i = k; i < n; i++) {

            freq2[s2[i] - 'a']++;        // add new char
            freq2[s2[i - k] - 'a']--;    // remove old char

            if(isFreqSame(freq1, freq2))
                return true;
        }

        return false;
    }
};
