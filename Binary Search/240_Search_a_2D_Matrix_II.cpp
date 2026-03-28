/*
Problem: Search a 2D Matrix II
Platform: LeetCode (LC 240)
Topic: Binary Search / Matrix

Matrix properties:
- Each row is sorted (left → right)
- Each column is sorted (top → bottom)

---------------------------------------------------------

Approach: Staircase Search (Optimal)

- Start from top-right corner
- If current > target → move left
- If current < target → move down

---------------------------------------------------------

Time Complexity: O(m + n)
Space Complexity: O(1)

Example:
Input:
[
 [1,  4,  7, 11, 15],
 [2,  5,  8, 12, 19],
 [3,  6,  9, 16, 22]
]
Target: 5

Output: true
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int target) {

        int m = v.size();
        int n = v[0].size();

        int r = 0;
        int c = n - 1;

        while(r < m && c >= 0) {

            if(v[r][c] == target) {
                return true;
            }
            else if(v[r][c] > target) {
                c--;   // move left
            }
            else {
                r++;   // move down
            }
        }

        return false;
    }
};
