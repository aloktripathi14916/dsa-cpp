/*
Problem: Robot Return to Origin
Platform: LeetCode (LC 657)
Topic: Strings / Simulation

---------------------------------------------------------

Approach:

- Track vertical (U/D) and horizontal (L/R) movement
- If final position is (0,0) → return true

---------------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(1)

Example:
Input: "UD"
Output: true
*/

class Solution {
public:
    bool judgeCircle(string moves) {
        
        int x = 0, y = 0;

        for(char c : moves) {
            if(c == 'U') x++;
            else if(c == 'D') x--;
            else if(c == 'L') y++;
            else if(c == 'R') y--;
        }

        return (x == 0 && y == 0);
    }
};
