/*
Problem: Subsets II
Platform: LeetCode (LC 90)
Topic: Recursion / Backtracking

---------------------------------------------------------

Approach:

- Sort array to group duplicates
- Use recursion (pick / not pick)
- While skipping, jump over duplicates

---------------------------------------------------------

Time Complexity: O(2^n)
Space Complexity: O(n)

Example:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
*/

class Solution {
public:
    void solve(vector<int>& nums, int i, vector<int>& curr, vector<vector<int>>& res) {
        
        int n = nums.size();

        if(i == n) {
            res.push_back(curr);
            return;
        }

        // pick
        curr.push_back(nums[i]);
        solve(nums, i + 1, curr, res);

        // backtrack
        curr.pop_back();

        // skip duplicates
        int idx = i + 1;
        while(idx < n && nums[idx] == nums[i]) idx++;

        // not pick
        solve(nums, idx, curr, res);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> curr;

        solve(nums, 0, curr, res);

        return res;
    }
};
