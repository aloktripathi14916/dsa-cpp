/*
Problem: Permutations
Platform: LeetCode (LC 46)
Topic: Recursion / Backtracking

---------------------------------------------------------

Approach:

- Fix one position at a time
- Swap current index with all possible elements
- Backtrack after recursion

---------------------------------------------------------

Time Complexity: O(n! * n)
Space Complexity: O(n)

Example:
Input: nums = [1,2,3]
Output: all permutations
*/

class Solution {
public:
    void generate(vector<int>& nums, int idx, vector<vector<int>>& ans) {
        
        int n = nums.size();

        if(idx == n) {
            ans.push_back(nums);
            return;
        }

        for(int i = idx; i < n; i++) {
            swap(nums[i], nums[idx]);

            generate(nums, idx + 1, ans);

            swap(nums[idx], nums[i]); // backtrack
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;

        generate(nums, 0, ans);

        return ans;
    }
};
