/*
Problem: Subsets
Platform: LeetCode (LC 78)
Topic: Recursion / Backtracking

---------------------------------------------------------

Approach:

- At each index, we have 2 choices:
    1. Include the element
    2. Exclude the element

- Generate all possible subsets using recursion

---------------------------------------------------------

Time Complexity: O(2^n * n)
Space Complexity: O(n)

Example:
Input: nums = [1,2]
Output: [[],[1],[2],[1,2]]
*/

class Solution {
public:
    void solve(vector<int>& nums, vector<int>& curr, int i, vector<vector<int>>& res) {
        
        if(i == nums.size()) {
            res.push_back(curr);
            return;
        }

        // include
        curr.push_back(nums[i]);
        solve(nums, curr, i + 1, res);

        // backtrack
        curr.pop_back();

        // exclude
        solve(nums, curr, i + 1, res);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int> curr;

        solve(nums, curr, 0, res);

        return res;
    }
};
