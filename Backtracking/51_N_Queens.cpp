/*
Problem: N-Queens
Platform: LeetCode (LC 51)
Topic: Backtracking

---------------------------------------------------------

Approach:

- Place queens row by row
- Check safety using:
    column + diagonals
- Backtrack after each placement

---------------------------------------------------------

Time Complexity: O(n!)
Space Complexity: O(n^2)

Example:
Input: n = 4
Output:
[
 [".Q..","...Q","Q...","..Q."],
 ["..Q.","Q...","...Q",".Q.."]
]
*/

class Solution {
public:

    bool isSafe(vector<string>& board, int row, int col, int n) {
        
        // column check
        for(int i = 0; i < row; i++) {
            if(board[i][col] == 'Q') return false;
        }

        // left diagonal
        for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q') return false;
        }

        // right diagonal
        for(int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if(board[i][j] == 'Q') return false;
        }

        return true;
    }

    void solve(vector<string>& board, vector<vector<string>>& ans, int n, int row) {
        
        if(row == n) {
            ans.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++) {
            
            if(isSafe(board, row, col, n)) {
                
                board[row][col] = 'Q';

                solve(board, ans, n, row + 1);

                board[row][col] = '.'; // backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));

        solve(board, ans, n, 0);

        return ans;
    }
};
