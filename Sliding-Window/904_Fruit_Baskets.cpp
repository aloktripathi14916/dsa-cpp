/*
Problem: Fruit Into Baskets
Platform: LeetCode (LC 904)
Topic: Sliding Window

---------------------------------------------------------

Approach:

- Use sliding window with hashmap
- Keep at most 2 distinct fruit types
- Expand window, shrink when invalid

---------------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(1)

Example:
Input: [1,2,1]
Output: 3
*/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        unordered_map<int, int> m;
        int st = 0, maxLen = 0;

        for(int end = 0; end < fruits.size(); end++) {

            m[fruits[end]]++;

            while(m.size() > 2) {
                m[fruits[st]]--;
                if(m[fruits[st]] == 0)
                    m.erase(fruits[st]);
                st++;
            }

            maxLen = max(maxLen, end - st + 1);
        }

        return maxLen;
    }
};
