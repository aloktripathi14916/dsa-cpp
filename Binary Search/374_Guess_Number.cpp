/*
Problem: Guess Number Higher or Lower
Platform: LeetCode (LC 374)
Topic: Binary Search

---------------------------------------------------------

Approach:

- Use binary search on range [1, n]
- Use guess(mid) API to decide direction

---------------------------------------------------------

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    int guessNumber(int n) {
        
        long long st = 1, end = n;

        while(st <= end) {

            long long mid = st + (end - st) / 2;

            int res = guess(mid);

            if(res == 0) {
                return mid;
            }
            else if(res == -1) {
                end = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }

        return -1;
    }
};
