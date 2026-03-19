/*
Problem: Sort Colors
Platform: LeetCode (LC 75)
Topic: Arrays / Two Pointer / Dutch National Flag

Given an array nums with n objects colored 0, 1, or 2, sort them **in-place**
so that objects of the same color are adjacent, with the colors in the order 0, 1, 2.

---------------------------------------------------------

Approach: Dutch National Flag Algorithm (Two Pointers)

Key Idea:
- Use three pointers: low, mid, high
- Traverse the array:
    - arr[mid] == 0 → swap with arr[low], move low & mid
    - arr[mid] == 1 → move mid
    - arr[mid] == 2 → swap with arr[high], move high
- Continue until mid > high

Time Complexity: O(n)
Space Complexity: O(1)

Example:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
*/

class Solution {
public:
    void sortColors(vector<int>& arr) {

        int n = arr.size();
        int low = 0, mid = 0, high = n - 1;

        while(mid <= high) {

            if(arr[mid] == 0) {
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }
            else if(arr[mid] == 1) {
                mid++;
            }
            else { // arr[mid] == 2
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};
