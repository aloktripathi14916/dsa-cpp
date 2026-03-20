/*
Problem: Next Permutation
Platform: LeetCode (LC 31)
Topic: Arrays / Permutation

Implement next permutation, which rearranges numbers into the
lexicographically next greater permutation.

If such arrangement is not possible, rearrange it as the lowest
possible order (i.e., sorted in ascending order).

---------------------------------------------------------

Approach:

1. Find the **pivot**:
   - Traverse from right and find first index `i`
     such that arr[i] < arr[i+1]

2. If no pivot found:
   - Array is in descending order → reverse whole array

3. Otherwise:
   - Find the next greater element from the right of pivot
   - Swap it with pivot

4. Reverse the suffix (right side of pivot)

---------------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(1)

Example:
Input: [1,2,3]
Output: [1,3,2]

Input: [3,2,1]
Output: [1,2,3]
*/

class Solution {
public:
    void nextPermutation(vector<int>& arr) {

        int n = arr.size();
        int piv = -1;

        // Step 1: Find pivot
        for(int i = n - 2; i >= 0; i--) {
            if(arr[i] < arr[i + 1]) {
                piv = i;
                break;
            }
        }

        // Step 2: If no pivot, reverse whole array
        if(piv == -1) {
            reverse(arr.begin(), arr.end());
            return;
        }

        // Step 3: Find next greater element and swap
        for(int i = n - 1; i > piv; i--) {
            if(arr[i] > arr[piv]) {
                swap(arr[i], arr[piv]);
                break;
            }
        }

        // Step 4: Reverse the suffix
        reverse(arr.begin() + piv + 1, arr.end());
    }
};
