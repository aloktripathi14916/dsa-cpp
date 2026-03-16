/*
Approach : Hash Set

Idea:
- Insert numbers from 1 to n into a set.
- Traverse the array and remove elements that appear.
- Remaining elements in the set are the missing numbers.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        int n = nums.size();
        vector<int> ans;

        unordered_set<int> s;

        for(int i = 1; i <= n; i++)
            s.insert(i);

        for(int i = 0; i < n; i++) {
            if(s.find(nums[i]) != s.end())
                s.erase(nums[i]);
        }

        for(auto x : s)
            ans.push_back(x);

        return ans;
    }
};
