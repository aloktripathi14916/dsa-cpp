/*
Problem: How Many Numbers Are Smaller Than the Current Number
Platform: LeetCode (LC 1365)
Topic: Arrays / Counting Sort

---------------------------------------------------------

Approach:

- Use frequency array (range 0–100)
- Convert to prefix sum
- For each number:
    answer = freq[num - 1]

---------------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        
        vector<int> freq(101, 0);

        // count frequency
        for(int num : nums) {
            freq[num]++;
        }

        // prefix sum
        for(int i = 1; i < 101; i++) {
            freq[i] += freq[i - 1];
        }

        vector<int> ans;

        for(int num : nums) {
            if(num == 0) ans.push_back(0);
            else ans.push_back(freq[num - 1]);
        }

        return ans;
    }
};
