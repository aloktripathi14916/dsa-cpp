/*
Problem: Detect Capital
Platform: LeetCode (LC 520)
Topic: Strings

---------------------------------------------------------

Approach:

A word is valid if:
1. All letters are uppercase (e.g., "USA")
2. All letters are lowercase (e.g., "leetcode")
3. Only the first letter is uppercase (e.g., "Google")

We count the number of uppercase letters and check:
- count == n → all uppercase
- count == 0 → all lowercase
- count == 1 and first letter uppercase → valid

---------------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(1)

Example:
Input: "USA"
Output: true

Input: "FlaG"
Output: false
*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        
        int count = 0;

        // count uppercase letters
        for(char c : word) {
            if(isupper(c)) count++;
        }

        // check conditions
        if(count == word.size()) return true;             // all uppercase
        if(count == 0) return true;                       // all lowercase
        if(count == 1 && isupper(word[0])) return true;   // only first uppercase

        return false;
    }
};
