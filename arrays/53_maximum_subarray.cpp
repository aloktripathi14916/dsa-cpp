// Problem: Maximum Subarray (LC 53)
// Platform: LeetCode
// Approach: Kadane's Algorithm
// Topic: Arrays / Dynamic Programming
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int sum = 0;
        int maxSum = INT_MIN;

        for(int x : nums)
        {
            sum += x;                     // extend current subarray
            maxSum = max(sum, maxSum);    // update maximum sum found so far

            if(sum < 0)                   // reset if current sum becomes negative
            {
                sum = 0;
            }
        }

        return maxSum;
    }
};
