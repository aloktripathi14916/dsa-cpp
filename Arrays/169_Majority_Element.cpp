/*
Problem: Majority Element
Platform: LeetCode (LC 169)
Topic: Arrays / Boyer-Moore Voting Algorithm

Approach:
- Use Boyer-Moore Voting Algorithm to find the majority element.
- Initialize `freq = 0` and `ans` to store the candidate.
- Traverse the array:
    - If freq is 0, pick current element as a new candidate.
    - If current element equals candidate, increment freq.
    - Otherwise, decrement freq.
- At the end, `ans` holds the majority element (appears more than n/2 times).

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int majorityElement(vector<int>& v) {
        int freq = 0;
        int ans = 0;

        for (int i = 0; i < v.size(); i++) {
            if (freq == 0) {
                ans = v[i];  // pick new candidate
            }

            if (v[i] == ans) {
                freq++;      // same as candidate
            } else {
                freq--;      // different, reduce count
            }
        }

        return ans;
    }
};
