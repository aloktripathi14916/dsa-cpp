/*
Problem: Boats to Save People
Platform: LeetCode (LC 881)
Topic: Greedy / Two Pointers

---------------------------------------------------------

Approach:

- Sort the array
- Use two pointers:
    st → lightest
    end → heaviest

- If they can share a boat → move both
- Else → send heaviest alone

---------------------------------------------------------

Time Complexity: O(n log n)
Space Complexity: O(1)

Example:
Input: nums = [3,2,2,1], limit = 3
Output: 3
*/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        sort(people.begin(), people.end());

        int st = 0, end = people.size() - 1;
        int boats = 0;

        while(st <= end) {

            if(people[st] + people[end] <= limit) {
                st++;
            }

            end--;
            boats++;
        }

        return boats;
    }
};
