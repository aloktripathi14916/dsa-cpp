/*
Problem: Intersection of Two Arrays
Platform: LeetCode (LC 349)
Topic: Hashing

---------------------------------------------------------

Approach:

- Store elements of nums1 in a set
- Traverse nums2:
    if element exists in set:
        add to result
        remove from set (to avoid duplicates)

---------------------------------------------------------

Time Complexity: O(n + m)
Space Complexity: O(n)

Example:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_set<int> s;
        
        for(int num : nums1) {
            s.insert(num);
        }

        vector<int> ans;

        for(int num : nums2) {
            if(s.find(num) != s.end()) {
                ans.push_back(num);
                s.erase(num);
            }
        }

        return ans;
    }
};
