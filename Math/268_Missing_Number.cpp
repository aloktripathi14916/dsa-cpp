/*
Problem: Missing Number
Platform: LeetCode (LC 268)
Topic: Math / Arrays

---------------------------------------------------------

Approach:

- Use formula:
    sum of 0 to n = n*(n+1)/2
- Subtract actual sum from expected sum
- Result is the missing number

---------------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(1)

Example:
Input: nums = [3,0,1]
Output: 2
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();

        long long expSum = (long long)n * (n + 1) / 2;
        long long actSum = 0;

        for(int num : nums) {
            actSum += num;
        }

        return expSum - actSum;
    }
};
