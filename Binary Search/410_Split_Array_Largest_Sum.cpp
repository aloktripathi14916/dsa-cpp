/*
Problem: Split Array Largest Sum
Platform: LeetCode (LC 410)
Topic: Arrays / Binary Search on Answer

Given an array nums and an integer k, split the array into k non-empty subarrays
such that the largest sum among these subarrays is minimized.
Return this minimized largest sum.

---------------------------------------------------------

Approach: Binary Search on Answer

Key Idea:
- The answer lies between max(nums) and sum(nums).
- Use binary search to find the **smallest largest sum**:
    1. Check if mid value is a valid largest sum (isValid function).
    2. If valid, try smaller mid (end = mid - 1).
    3. Else, try larger mid (st = mid + 1).

isValid function:
- Try to split array into subarrays where each subarray sum <= mid.
- Count how many subarrays needed (div).
- If div <= k, mid is valid.

Time Complexity: O(n * log(sum(nums)))
Space Complexity: O(1)

Example:
Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: Split into [7,2,5] and [10,8], largest sum = 18
*/

class Solution {
public:

    // Check if it's possible to split array into <= k subarrays
    // with largest sum <= mid
    bool isValid(vector<int>& v, int k, int mid) {
        int div = 1, sum = 0;

        for(int i = 0; i < v.size(); i++) {

            if(v[i] > mid) return false;

            if(sum + v[i] <= mid)
                sum += v[i];
            else {
                sum = v[i];
                div++;
            }
        }

        return (div <= k);
    }

    int splitArray(vector<int>& v, int k) {

        int sum = 0, maxval = 0;

        for(int i = 0; i < v.size(); i++) {
            sum += v[i];
            maxval = max(maxval, v[i]);
        }

        int st = maxval;
        int end = sum;
        int ans = -1;

        while(st <= end) {
            int mid = st + (end - st) / 2;

            if(isValid(v, k, mid)) {
                ans = mid;
                end = mid - 1;   // try smaller max sum
            } else {
                st = mid + 1;     // need larger max sum
            }
        }

        return ans;
    }
};
