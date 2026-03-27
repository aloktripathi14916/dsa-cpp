/*
Problem: Sqrt(x)
Platform: LeetCode (LC 69)
Topic: Binary Search

Given a non-negative integer x, return the square root of x
rounded down to the nearest integer.

---------------------------------------------------------

Approach: Binary Search

- Search in range [0, x]
- For each mid:
    if(mid * mid == x) → return mid
    if(mid * mid < x)  → move right, store answer
    if(mid * mid > x)  → move left

---------------------------------------------------------

Time Complexity: O(log x)
Space Complexity: O(1)

Example:
Input: x = 8
Output: 2  (since sqrt(8) ≈ 2.828)

Input: x = 16
Output: 4
*/

class Solution {
public:
    int mySqrt(int x) {

        long long st = 0, end = x;
        int ans = 0;

        while(st <= end) {

            long long mid = st + (end - st) / 2;

            if(mid * mid == x) {
                return mid;
            }
            else if(mid * mid < x) {
                ans = mid;
                st = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return ans;
    }
};
