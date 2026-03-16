/*
Problem: Container With Most Water
Platform: LeetCode (LC 11)
Topic: Arrays / Two Pointer

You are given an array height where each element represents
the height of a vertical line on the x-axis. Find two lines,
which together with the x-axis forms a container, such that
the container contains the most water.

Approach:
- Use two pointers: start at left (st) and right (end).
- Calculate current area = min(height[st], height[end]) * (end - st)
- Update maxArea if current area is larger.
- Move the pointer with the smaller height inward.
- Repeat until pointers meet.

Time Complexity: O(n)
Space Complexity: O(1)

Example:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: Lines at index 1 and 8 form the container with max area 49.
*/

class Solution {
public:
    int maxArea(vector<int>& v) {

        int st = 0, end = v.size() - 1;
        int maxarea = 0;

        while (st < end) {

            int height = min(v[st], v[end]);
            int width = end - st;
            int area = height * width;

            if (area > maxarea)
                maxarea = area;

            // Move the pointer pointing to smaller height
            if (v[st] < v[end])
                st++;
            else
                end--;
        }

        return maxarea;
    }
};
