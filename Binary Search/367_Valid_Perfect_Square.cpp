/*
Problem: Valid Perfect Square
Platform: LeetCode (LC 367)
Topic: Binary Search

Given a positive integer num, return true if num is a
perfect square, otherwise false.

---------------------------------------------------------

Approach: Binary Search

- Search in range [0, num]
- For each mid:
    if(mid * mid == num) → true
    if(mid * mid < num)  → move right
    if(mid * mid > num)  → move left

---------------------------------------------------------

Time Complexity: O(log n)
Space Complexity: O(1)

Example:
Input: num = 16
Output: true

Input: num = 14
Output: false
*/

class Solution {
public:
    bool isPerfectSquare(int num) {

        long long st = 0, end = num;

        while(st <= end) {

            long long mid = st + (end - st) / 2;

            if(mid * mid == num) {
                return true;
            }
            else if(mid * mid < num) {
                st = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return false;
    }
};
