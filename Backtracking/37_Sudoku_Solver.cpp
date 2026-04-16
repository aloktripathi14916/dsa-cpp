/*
Problem: Sudoku Solver
Platform: LeetCode (LC 37)
Topic: Backtracking

---------------------------------------------------------

Approach:

- Traverse board cell by cell
- If empty → try digits 1 to 9
- Check validity (row, column, box)
- Place digit → recurse
- If fails → backtrack

---------------------------------------------------------

Time Complexity: Exponential (worst case)
Space Complexity: O(1) (excluding recursion stack)
*/

class Solution {
public:

    bool isSafe(vector<vector<char>>& board, int row, int col, char dig) {
        
        // row check
        for(int j = 0; j < 9; j++)
            if(board[row][j] == dig) return false;

        // column check
        for(int i = 0; i < 9; i++)
            if(board[i][col] == dig) return false;

        // 3x3 box check
        int startrow = (row / 3) * 3;
        int startcol = (col / 3) * 3;

        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                if(board[startrow + i][startcol + j] == dig)
                    return false;

        return true;
    }

    bool solve(vector<vector<char>>& board, int row, int col) {
        
        if(row == 9) return true;

        int nextrow = row, nextcol = col + 1;

        if(nextcol == 9) {
            nextrow = row + 1;
            nextcol = 0;
        }

        if(board[row][col] != '.') {
            return solve(board, nextrow, nextcol);
        }

        for(char dig = '1'; dig <= '9'; dig++) {
            
            if(isSafe(board, row, col, dig)) {

                board[row][col] = dig;

                if(solve(board, nextrow, nextcol))
                    return true;

                board[row][col] = '.'; // backtrack
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};
