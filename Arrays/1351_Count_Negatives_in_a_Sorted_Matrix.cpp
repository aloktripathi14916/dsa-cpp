/*
Problem: Count Negative Numbers in a Sorted Matrix
Platform: LeetCode (LC 1351)
Topic: Arrays / Matrix / Two Pointer

You are given an m x n matrix where each row and column
is sorted in non-increasing order.

Return the number of negative numbers in the grid.

-----------------------------------------------------

Approach: Two Pointer Traversal

Key Idea:
- Since rows are sorted decreasingly, once we find a negative
  number in a row, all elements to the right are also negative.
- Start from the **top-right corner** of the matrix.
- Move left while elements are negative.
- Count negatives in that row as (n - c - 1).

Time Complexity: O(m + n)
Space Complexity: O(1)

Example:
Input:
grid = [[4,3,2,-1],
        [3,2,1,-1],
        [1,1,-1,-2],
        [-1,-1,-2,-3]]

Output: 8
*/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        int c = n - 1;   // start from top-right column

        for (int r = 0; r < m; r++) {

            // move left while numbers are negative
            while (c >= 0 && grid[r][c] < 0) {
                c--;
            }

            // count negatives in this row
            count += (n - c - 1);
        }

        return count;
    }
};
