/*
Problem: Search a 2D Matrix
Platform: LeetCode (LC 74)
Topic: Binary Search

You are given an m x n matrix with properties:
- Each row is sorted
- First element of each row > last element of previous row

Return true if target exists.

---------------------------------------------------------

Approach 1: Two Binary Searches (Your Approach)

1. First find the correct row using binary search
2. Then apply binary search in that row

Time Complexity: O(log m + log n)
Space Complexity: O(1)

---------------------------------------------------------

Approach 2: Treat Matrix as 1D (Optimal)

- Flatten matrix virtually
- Index mapping:
    row = mid / n
    col = mid % n

Time Complexity: O(log (m*n))
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int target) {

        int m = v.size();
        int n = v[0].size();

        // -------- Row Selection --------
        int row = -1;
        int st = 0, end = m - 1;

        while(st <= end) {
            int mid = st + (end - st) / 2;

            if(v[mid][0] <= target && v[mid][n - 1] >= target) {
                row = mid;
                break;
            }
            else if(v[mid][0] > target) {
                end = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }

        if(row == -1) return false;

        // -------- Binary Search in Row --------
        int left = 0, right = n - 1;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if(v[row][mid] == target) {
                return true;
            }
            else if(v[row][mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return false;
    }
};
