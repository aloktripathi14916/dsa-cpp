/*
Problem: Find All Numbers Disappeared in an Array
Platform: LeetCode (LC 448)
Topic: Array / In-place Hashing

---------------------------------------------------------

Approach:

- Use index marking technique
- For each number x:
    mark index (x-1) as negative
- After marking:
    indices with positive values → missing numbers

---------------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(1) (excluding output)

Example:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> ans;

        // Mark indices
        for(int i = 0; i < n; i++) {
            int index = abs(nums[i]) - 1;
            if(nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }

        // Find missing numbers
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) {
                ans.push_back(i + 1);
            }
        }

        return ans;
    }
};
