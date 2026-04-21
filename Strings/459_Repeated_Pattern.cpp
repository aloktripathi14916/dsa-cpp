/*
Problem: Repeated Substring Pattern
Platform: LeetCode (LC 459)
Topic: Strings / Brute Force

---------------------------------------------------------

Approach:

- Try all possible substring lengths k
- If k divides n:
    - form repeated string using first k chars
    - compare with original string

---------------------------------------------------------

Time Complexity: O(n^2)
Space Complexity: O(n)
*/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        int n = s.size();

        for(int k = 1; k <= n / 2; k++) {

            if(n % k != 0) continue;

            string block = s.substr(0, k);
            string formed = "";

            int times = n / k;

            for(int t = 0; t < times; t++) {
                formed += block;
            }

            if(formed == s)
                return true;
        }

        return false;
    }
};
