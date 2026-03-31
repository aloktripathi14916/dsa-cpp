/*
Problem: 3Sum
Platform: LeetCode (LC 15)
Topic: Two Pointers

---------------------------------------------------------

Approach:

1. Sort the array
2. Fix one element (i)
3. Use two pointers (left, right) to find pairs
4. Skip duplicates to avoid repeated triplets

---------------------------------------------------------

Time Complexity: O(n²)
Space Complexity: O(1) (excluding output)

Example:
Input: [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {

            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int st = i + 1, end = n - 1;

            while (st < end) {

                int sum = nums[i] + nums[st] + nums[end];

                if (sum == 0) {

                    ans.push_back({nums[i], nums[st], nums[end]});

                    while (st < end && nums[st] == nums[st + 1]) st++;
                    while (st < end && nums[end] == nums[end - 1]) end--;

                    st++;
                    end--;
                }
                else if (sum < 0) {
                    st++;
                }
                else {
                    end--;
                }
            }
        }

        return ans;
    }
};
