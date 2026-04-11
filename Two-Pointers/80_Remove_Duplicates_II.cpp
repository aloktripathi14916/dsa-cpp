/*
Problem: Remove Duplicates from Sorted Array II
Platform: LeetCode (LC 80)
Topic: Two Pointers

---------------------------------------------------------

Approach:

- Allow at most 2 occurrences of each element
- Use pointer 'idx' to place valid elements
- Compare current element with nums[idx-2]:
    if different → include
    else → skip

---------------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(1)

Example:
Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size() <= 2) return nums.size();

        int idx = 2;

        for(int i = 2; i < nums.size(); i++) {
            if(nums[i] != nums[idx - 2]) {
                nums[idx] = nums[i];
                idx++;
            }
        }

        return idx;
    }
};
