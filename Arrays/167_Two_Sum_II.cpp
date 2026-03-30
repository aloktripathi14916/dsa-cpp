/*
Problem: Two Sum II - Input Array Is Sorted
Platform: LeetCode (LC 167)
Topic: Two Pointers

---------------------------------------------------------

Approach: Two Pointers

- Since array is sorted, use two pointers:
    left = 0, right = n - 1
- If sum > target → move right--
- If sum < target → move left++
- If equal → return indices (1-based)

---------------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(1)

Example:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {

        int st = 0, end = arr.size() - 1;

        while(st < end) {

            int sum = arr[st] + arr[end];

            if(sum == target) {
                return {st + 1, end + 1}; // 1-based indexing
            }
            else if(sum > target) {
                end--;
            }
            else {
                st++;
            }
        }

        return {};
    }
};
