/*
Problem: Pow(x, n)
Platform: LeetCode (LC 50)
Topic: Math / Binary Exponentiation

Approach:
- Use **binary exponentiation** for efficient power calculation.
- Convert `n` to `long long` to handle `INT_MIN` safely.
- If `n` is negative, invert `x` and make `n` positive.
- Loop while power > 0:
    - If current power is odd, multiply `ans` by `x`.
    - Square `x` and halve the power.
- Return `ans`.

Time Complexity: O(log n)
Space Complexity: O(1)

Example:
Input: x = 2.0, n = 10
Output: 1024.0
*/

class Solution {
public:
    double myPow(double x, int n) {
        long long power = n;   // handle negative n safely
        double ans = 1.0;

        if (power < 0) {
            x = 1 / x;
            power = -power;
        }

        while (power > 0) {
            if (power % 2 == 1) {
                ans *= x;  // multiply when power is odd
            }
            x = x * x;      // square x
            power /= 2;     // halve power
        }

        return ans;
    }
};
