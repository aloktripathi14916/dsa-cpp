/*
Problem: 4Sum
Platform: LeetCode (LC 18)
Topic: Two Pointers

---------------------------------------------------------

Approach:

1. Sort the array
2. Fix two elements (i, j)
3. Use two pointers (left, right) for remaining sum
4. Skip duplicates to avoid repeated quadruplets

---------------------------------------------------------

Time Complexity: O(n³)
Space Complexity: O(1) (excluding output)

Example:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n - 3; i++) {

            if(i > 0 && nums[i] == nums[i - 1]) continue;

            for(int j = i + 1; j < n - 2; j++) {

                if(j > i + 1 && nums[j] == nums[j - 1]) continue;

                int st = j + 1, end = n - 1;

                while(st < end) {

                    long long sum = (long long)nums[i] + nums[j] + nums[st] + nums[end];

                    if(sum == target) {

                        ans.push_back({nums[i], nums[j], nums[st], nums[end]});

                        while(st < end && nums[st] == nums[st + 1]) st++;
                        while(st < end && nums[end] == nums[end - 1]) end--;

                        st++;
                        end--;
                    }
                    else if(sum < target) {
                        st++;
                    }
                    else {
                        end--;
                    }
                }
            }
        }

        return ans;
    }
};
