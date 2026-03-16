/*
Problem: Find All Numbers Disappeared in an Array
Platform: LeetCode (LC 448)
Topic: Arrays / Hashing

Given an array nums of size n where nums[i] is in the range [1, n],
some elements appear twice and others appear once.

Return all the numbers in the range [1, n] that do not appear in nums.

---------------------------------------------------------

Approach 1: In-place Marking (Optimal)

Idea:
- Use the index as a marker.
- For each value x in the array, mark index (x-1) as visited
  by making nums[x-1] negative.
- After marking, any index with a positive value means
  that number (index+1) never appeared.

Time Complexity: O(n)
Space Complexity: O(1) (excluding output)

---------------------------------------------------------
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            int index = abs(nums[i]) - 1;

            if(nums[index] > 0)
                nums[index] = -nums[index];
        }

        for(int i = 0; i < n; i++) {
            if(nums[i] > 0)
                ans.push_back(i + 1);
        }

        return ans;
    }
};
