/*
Problem: Find the Duplicate Number
Platform: LeetCode (LC 287)
Topic: Linked List (Cycle Detection)

---------------------------------------------------------

Approach: Floyd’s Cycle Detection (Tortoise & Hare)

- Treat array as linked list:
    index → value → next index

- Step 1: Detect cycle
    slow = nums[slow]
    fast = nums[nums[fast]]

- Step 2: Find entry point of cycle
    reset slow to start
    move both one step at a time

- Meeting point = duplicate number

---------------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(1)

Example:
Input: [1,3,4,2,2]
Output: 2
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow = nums[0];
        int fast = nums[0];

        // Step 1: Detect cycle
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        // Step 2: Find entry point
        slow = nums[0];

        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
