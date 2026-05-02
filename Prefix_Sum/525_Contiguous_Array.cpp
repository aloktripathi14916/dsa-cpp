/*
Problem: Contiguous Array
Platform: LeetCode (LC 525)
Topic: Prefix Sum / Hashing

---------------------------------------------------------

Approach:

Convert:
0 -> -1
1 -> +1

Then the problem becomes:
find the longest subarray with sum = 0.

Use prefix sum + hashmap:
- store first occurrence of each prefix sum
- if same sum appears again,
  the subarray between them has zero sum

---------------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(n)

Example:
Input: [0,1,0]
Output: 2
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        
        unordered_map<int, int> mp;
        mp[0] = -1;

        int sum = 0;
        int maxLen = 0;

        for(int i = 0; i < nums.size(); i++) {
            
            if(nums[i] == 0)
                sum += -1;
            else
                sum += 1;

            if(mp.count(sum))
                maxLen = max(maxLen, i - mp[sum]);
            else
                mp[sum] = i;
        }

        return maxLen;
    }
};
