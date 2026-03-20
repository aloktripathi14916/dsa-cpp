/*
Problem: Merge Sorted Array
Platform: LeetCode (LC 88)
Topic: Arrays / Two Pointer

You are given two sorted integer arrays nums1 and nums2,
and two integers m and n, representing the number of elements
in nums1 and nums2 respectively.

Merge nums2 into nums1 as one sorted array.
Note: nums1 has enough space (size = m + n) to hold additional elements.

---------------------------------------------------------

Approach: Two Pointers (From End)

Key Idea:
- Start filling nums1 from the **back** to avoid overwriting elements.
- Compare elements from end of both arrays:
    - Place the larger one at the end (k index)
- If nums2 still has elements left, copy them.

Time Complexity: O(m + n)
Space Complexity: O(1)

Example:
Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6], n = 3

Output:
[1,2,2,3,5,6]
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m - 1;        // pointer for nums1
        int j = n - 1;        // pointer for nums2
        int k = m + n - 1;    // pointer for merged array

        // Merge from the end
        while(i >= 0 && j >= 0) {

            if(nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }

        // Copy remaining elements of nums2 (if any)
        while(j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};
