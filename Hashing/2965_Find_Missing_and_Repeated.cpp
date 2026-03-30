/*
Problem: Find Missing and Repeated Values
Platform: LeetCode (LC 2965)
Topic: Hashing + Math

---------------------------------------------------------

Approach:

1. Use unordered_set to find repeated number (a)
2. Compute:
    expected sum = n²(n² + 1)/2
    actual sum from grid
3. Use formula:
    missing (b) = expected + a - actual

---------------------------------------------------------

Time Complexity: O(n²)
Space Complexity: O(n²)

Example:
Input:
[[1,3],
 [2,2]]

Output: [2,4]
*/

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        int n = grid.size();
        long long expectedSum = (long long)(n*n) * (n*n + 1) / 2;
        long long actualSum = 0;

        unordered_set<int> s;
        int repeated = -1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {

                int val = grid[i][j];
                actualSum += val;

                if(s.count(val)) {
                    repeated = val;
                }

                s.insert(val);
            }
        }

        int missing = expectedSum + repeated - actualSum;

        return {repeated, missing};
    }
};
