/*
Problem: Count Commas
Platform: LeetCode (LC 3870)
Topic: Math / Counting

---------------------------------------------------------

Approach:

- Numbers gain commas based on digit length:
    1–999 → 0 commas
    1000–999999 → 1 comma each
    1000000–999999999 → 2 commas each
    ...

- For each range:
    count numbers in range × commas per number

---------------------------------------------------------

Time Complexity: O(log n)
Space Complexity: O(1)

Example:
Input: n = 5000
Output: 4001
*/

class Solution {
public:
    int countCommas(int n) {
        
        long long start = 1000;
        int commas = 1;
        long long ans = 0;

        while(start <= n) {
            
            long long end = start * 1000 - 1;

            // take only valid range within n
            long long upper = min((long long)n, end);

            if(upper >= start) {
                ans += (upper - start + 1) * commas;
            }

            start *= 1000;
            commas++;
        }

        return ans;
    }
};
