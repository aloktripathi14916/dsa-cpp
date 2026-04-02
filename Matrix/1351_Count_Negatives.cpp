/*
Problem: Count Negative Numbers in a Sorted Matrix
Platform: LeetCode (LC 1351)
Topic: Matrix

---------------------------------------------------------

Approach: Optimized Traversal (Staircase)

- Start from top-right corner
- If element is negative → move left
- Else → move down
- Count negatives efficiently using pointer

---------------------------------------------------------

Time Complexity: O(m + n)
Space Complexity: O(1)

Example:
Input:
[
 [4,3,2,-1],
 [3,2,1,-1],
 [1,1,-1,-2],
 [-1,-1,-2,-3]
]

Output: 8
*/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        int c = n - 1;

        for(int r = 0; r < m; r++) {

            while(c >= 0 && grid[r][c] < 0) {
                c--;
            }

            count += (n - c - 1);
        }

        return count;
    }
};
