/*
Problem: Remove Element
Platform: LeetCode (LC 27)
Topic: Two Pointers

---------------------------------------------------------

Approach:

- Use two pointers:
    st → start
    end → end of valid range

- If nums[st] == val:
    swap with end and shrink range
- Else:
    move forward

---------------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(1)

Note:
Order of elements is NOT preserved
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int st = 0, end = nums.size() - 1;

        while(st <= end) {

            if(nums[st] == val) {
                swap(nums[st], nums[end]);
                end--;
            } else {
                st++;
            }
        }

        return end + 1;
    }
};
