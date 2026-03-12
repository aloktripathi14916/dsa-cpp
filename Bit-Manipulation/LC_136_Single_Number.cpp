/*
Problem: Single Number
Platform: LeetCode (LC 136)
Topic: Bit Manipulation / XOR

Approach:
- Use the XOR property to cancel out duplicate numbers.
- XOR of a number with itself is 0.
- XOR of a number with 0 is the number itself.
- Since every element appears twice except one, all duplicate
  numbers cancel out and we are left with the single number.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int ans = 0;   // will store the final single number

        // XOR all elements of the array
        for (int i : nums) {
            ans = ans ^ i;
        }

        return ans;
    }
};
