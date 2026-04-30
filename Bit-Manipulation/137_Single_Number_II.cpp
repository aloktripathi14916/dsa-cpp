/*
Problem: Single Number II
Platform: LeetCode (LC 137)
Topic: Bit Manipulation

---------------------------------------------------------

Approach:

Every element appears exactly 3 times except one.

For each bit position from 0 to 31:
- count how many numbers have that bit set
- if count % 3 != 0, then the unique number has that bit set

Reconstruct the answer bit by bit.

---------------------------------------------------------

Time Complexity: O(32 * n) ≈ O(n)
Space Complexity: O(1)

Example:
Input: [2,2,3,2]
Output: 3
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int ans = 0;

        for(int bit = 0; bit < 32; bit++) {
            int count = 0;

            for(int num : nums) {
                if(num & (1 << bit))
                    count++;
            }

            if(count % 3) {
                ans |= (1 << bit);
            }
        }

        return ans;
    }
};
