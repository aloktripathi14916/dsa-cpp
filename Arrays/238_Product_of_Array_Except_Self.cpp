/*
Problem: Product of Array Except Self
Platform: LeetCode (LC 238)
Topic: Arrays / Prefix & Suffix Products

Given an array nums of n integers, return an array output such that
output[i] is equal to the product of all the elements of nums except nums[i].

Note: Solve it **without division** and in O(n) time.

---------------------------------------------------------
Approach: Prefix & Suffix Products (Optimal)
1. Create an answer array ans, initialized with 1.
2. Fill ans[i] with the product of all elements **before i** (prefix product).
3. Traverse the array from the end, maintaining a **suffix product**.
4. Multiply ans[i] by suffix product to include all elements **after i**.
5. Return ans.

Time Complexity: O(n)
Space Complexity: O(1) extra space (output array not counted)

Example:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& v) {

        int n = v.size();
        vector<int> ans(n, 1);

        // Compute prefix products
        for(int i = 1; i < n; i++) {
            ans[i] = ans[i-1] * v[i-1];
        }

        // Compute suffix products and multiply
        int suffix = 1;
        for(int j = n-2; j >= 0; j--) {
            suffix = suffix * v[j+1];
            ans[j] *= suffix;
        }

        return ans;
    }
};
