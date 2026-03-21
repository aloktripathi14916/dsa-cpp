/*
Problem: Reverse String
Platform: LeetCode (LC 344)
Topic: Arrays / Two Pointer

Write a function that reverses a string in-place.  

---------------------------------------------------------

Approach: Two Pointers

1. Use two pointers: `st` at start, `end` at end.
2. Swap elements at `st` and `end`.
3. Move pointers inward until they meet.

Time Complexity: O(n)
Space Complexity: O(1) (in-place)

Example:
Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
*/

class Solution {
public:
    void reverseString(vector<char>& str) {

        int st = 0, end = str.size() - 1;

        while(st < end) {
            swap(str[st], str[end]);
            st++;
            end--;
        }
    }
};
