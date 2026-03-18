/*
Problem: Peak Index in a Mountain Array
Platform: LeetCode (LC 852)
Topic: Arrays / Binary Search

An array arr is called a mountain if:
- arr.length >= 3
- There exists some i (0 < i < arr.length-1) such that:
    - arr[0] < arr[1] < ... < arr[i]
    - arr[i] > arr[i+1] > ... > arr[arr.length-1]

Return the index i of the peak element.

---------------------------------------------------------

Approach: Binary Search (Find Peak)

Key Idea:
- For any mid index:
    - If arr[mid] < arr[mid+1], peak lies to the **right**
    - Else, peak lies to the **left or at mid**
- Narrow down search space until st == end → peak index

Time Complexity: O(log n)
Space Complexity: O(1)

Example:
Input: arr = [0,1,0]
Output: 1
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& v) {

        int st = 0;
        int end = v.size() - 1;

        while(st < end) {

            int mid = st + (end - st) / 2;

            if(v[mid] < v[mid + 1]) {
                st = mid + 1;   // move right
            } else {
                end = mid;      // move left (keep mid)
            }
        }

        return st;   // peak index
    }
};
