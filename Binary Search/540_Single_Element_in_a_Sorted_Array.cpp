/*
Problem: Single Element in a Sorted Array
Platform: LeetCode (LC 540)
Topic: Arrays / Binary Search

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once. Find this single element.

---------------------------------------------------------

Approach: Binary Search with Index Parity

Key Idea:
- Every pair occupies **even-odd indices**.
- If mid is even:
    - If v[mid] == v[mid+1], single element is **right**
    - Else, single element is **left or at mid**
- If mid is odd:
    - If v[mid] == v[mid+1], single element is **left**
    - Else, single element is **right**
- Continue until single element is found.

Time Complexity: O(log n)
Space Complexity: O(1)

Example:
Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& v) {

        int n = v.size();
        if(n == 1) return v[0];

        int st = 0, end = n - 1;

        while(st <= end) {
            int mid = st + (end - st) / 2;

            // Edge cases
            if(mid == 0 && v[mid] != v[mid+1]) return v[mid];
            if(mid == n-1 && v[mid] != v[mid-1]) return v[mid];
            if(v[mid] != v[mid-1] && v[mid] != v[mid+1]) return v[mid];

            // Binary search based on index parity
            if(mid % 2 == 0) {
                if(v[mid] == v[mid+1])
                    st = mid + 2;
                else
                    end = mid - 1;
            } else { // mid is odd
                if(v[mid] == v[mid+1])
                    end = mid - 1;
                else
                    st = mid + 1;
            }
        }

        return -1; // should never reach here
    }
};
