/*
Problem: Two Sum
Platform: LeetCode (LC 1)
Topic: Array, Hashing

---------------------------------------------------------

Approach: Hash Map

- Use an unordered_map to store each number and its index.
- For each element `v[i]`, check if `target - v[i]` exists in the map.
- If yes, return indices; otherwise, store `v[i]` in the map.

Time Complexity: O(n)
Space Complexity: O(n)

Example:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: nums[0] + nums[1] == 9
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& v, int t) {
        unordered_map<int,int> m;
        vector<int> ans;

        for(int i = 0; i < v.size(); i++) {
            int first = v[i];
            int second = t - first;

            if(m.find(second) != m.end()) {
                ans.push_back(i);
                ans.push_back(m[second]);
                break;
            }

            m[first] = i;
        }

        return ans;
    }
};
