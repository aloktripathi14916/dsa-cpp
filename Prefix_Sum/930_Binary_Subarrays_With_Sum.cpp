/*
Problem: Binary Subarrays With Sum
Platform: LeetCode (LC 930)
Topic: Prefix Sum / Hashing

---------------------------------------------------------

Approach:

Use prefix sum and hashmap.

If current prefix sum is 'sum',
we need previous prefix sums equal to (sum - goal).

Each such previous occurrence contributes one valid subarray.

---------------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(n)

Example:
Input: nums = [1,0,1,0,1], goal = 2
Output: 4
*/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        unordered_map<int, int> mp;
        mp[0] = 1;

        int sum = 0;
        int count = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if(mp.find(sum - goal) != mp.end()) {
                count += mp[sum - goal];
            }

            mp[sum]++;
        }

        return count;
    }
};
