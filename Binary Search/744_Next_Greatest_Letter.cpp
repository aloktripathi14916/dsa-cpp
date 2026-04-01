/*
Problem: Find Smallest Letter Greater Than Target
Platform: LeetCode (LC 744)
Topic: Binary Search

---------------------------------------------------------

Approach:

- Find the smallest character strictly greater than target
- Use binary search (upper bound concept)
- If not found, return first element (circular array)

---------------------------------------------------------

Time Complexity: O(log n)
Space Complexity: O(1)

Example:
Input: letters = ['c','f','j'], target = 'a'
Output: 'c'

Input: letters = ['c','f','j'], target = 'j'
Output: 'c'
*/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        int n = letters.size();
        int st = 0, end = n - 1;

        char ans = letters[0]; // handles wrap-around

        while(st <= end) {

            int mid = st + (end - st) / 2;

            if(letters[mid] > target) {
                ans = letters[mid];
                end = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }

        return ans;
    }
};
