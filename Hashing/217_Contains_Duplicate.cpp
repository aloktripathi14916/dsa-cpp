/*
Problem: Contains Duplicate
Platform: LeetCode (LC 217)
Topic: Hashing

---------------------------------------------------------

Approach:

- Use unordered_set to track seen elements
- If element already exists → duplicate found

---------------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(n)

Example:
Input: nums = [1,2,3,1]
Output: true
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_set<int> seen;

        for(int num : nums) {
            if(seen.find(num) != seen.end()) {
                return true;
            }
            seen.insert(num);
        }

        return false;
    }
};
