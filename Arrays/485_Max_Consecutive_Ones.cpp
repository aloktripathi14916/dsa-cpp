/*
Problem: Max Consecutive Ones
Platform: LeetCode (LC 485)
Topic: Arrays

---------------------------------------------------------

Approach:

- Traverse array
- Count consecutive 1s
- Reset count when 0 appears
- Track maximum count

---------------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(1)

Example:
Input: nums = [1,1,0,1,1,1]
Output: 3
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int count = 0, maxCount = 0;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] == 1) {
                count++;
                maxCount = max(maxCount, count);
            }
            else {
                count = 0;
            }
        }

        return maxCount;
    }
};
