/*
Problem: Find All Anagrams in a String
Platform: LeetCode (LC 438)
Topic: Sliding Window / Hashing

---------------------------------------------------------

Approach:

- Use fixed-size sliding window of size k
- Maintain frequency arrays for pattern and window
- Slide window and compare frequencies

---------------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(1)

Example:
Input: s = "cbaebabacd", p = "abc"
Output: [0, 6]
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        vector<int> ans;

        vector<int> freqP(26, 0);
        for(char c : p) {
            freqP[c - 'a']++;
        }

        vector<int> freqS(26, 0);
        int k = p.size();

        for(int i = 0; i < s.size(); i++) {

            freqS[s[i] - 'a']++;

            if(i >= k) {
                freqS[s[i - k] - 'a']--;
            }

            if(freqS == freqP) {
                ans.push_back(i - k + 1);
            }
        }

        return ans;
    }
};
