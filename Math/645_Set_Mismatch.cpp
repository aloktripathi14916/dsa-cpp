/*
Problem: Set Mismatch
Platform: LeetCode (LC 645)
Topic: Arrays / Math / Hashing

---------------------------------------------------------

Approach:

- One number is duplicated, one is missing
- Compute:
    expected sum = n*(n+1)/2
    actual sum = sum of array

- Find duplicate using hashmap
- Use formula:
    missing = duplicate + expectedSum - actualSum

---------------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(n)

Example:
Input: nums = [1,2,2,4]
Output: [2,3]
*/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        
        int n = nums.size();
        unordered_map<int, int> freq;

        long long expSum = (long long)n * (n + 1) / 2;
        long long actSum = 0;

        int duplicate = -1;

        for(int num : nums) {
            actSum += num;

            freq[num]++;
            if(freq[num] == 2) {
                duplicate = num;
            }
        }

        int missing = duplicate + expSum - actSum;

        return {duplicate, missing};
    }
};
