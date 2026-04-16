/*
Problem: Reverse Vowels of a String
Platform: LeetCode (LC 345)
Topic: Two Pointers

---------------------------------------------------------

Approach:

- Use two pointers from start and end
- Move pointers until vowels found
- Swap vowels

---------------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(1)

Example:
Input: "hello"
Output: "holle"
*/

class Solution {
public:

    bool isVowel(char c) {
        c = tolower(c);
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }

    string reverseVowels(string s) {
        
        int st = 0, end = s.size() - 1;

        while(st < end) {

            while(st < end && !isVowel(s[st])) st++;
            while(st < end && !isVowel(s[end])) end--;

            if(st < end) {
                swap(s[st], s[end]);
                st++;
                end--;
            }
        }

        return s;
    }
};
