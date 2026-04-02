/*
Problem: Concatenation of Array
Platform: LeetCode (LC 1929)
Topic: Arrays

---------------------------------------------------------

Approach:

- Create a new array of size 2*n
- Copy original array twice

---------------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(n)

Example:
Input: nums = [1,2,1]
Output: [1,2,1,1,2,1]
*/

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans(2 * n);

        for(int i = 0; i < n; i++) {
            ans[i] = nums[i];
            ans[i + n] = nums[i];
        }

        return ans;
    }
};
