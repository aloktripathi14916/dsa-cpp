/*
Problem: 3Sum Closest
Platform: LeetCode (LC 16)
Topic: Two Pointers / Sorting

---------------------------------------------------------

Approach:

- Sort the array
- Fix one element
- Use two pointers to find closest sum

---------------------------------------------------------

Time Complexity: O(n^2)
Space Complexity: O(1)

Example:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int closestSum = nums[0] + nums[1] + nums[2];

        for(int i = 0; i < n - 2; i++) {

            int st = i + 1, end = n - 1;

            while(st < end) {

                int sum = nums[i] + nums[st] + nums[end];

                // update closest first
                if(abs(sum - target) < abs(closestSum - target)) {
                    closestSum = sum;
                }

                if(sum > target) {
                    end--;
                } else {
                    st++;
                }
            }
        }

        return closestSum;
    }
};
