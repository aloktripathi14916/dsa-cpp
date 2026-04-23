/*
Problem: Bulls and Cows
Platform: LeetCode (LC 299)
Topic: Hashing / Strings

---------------------------------------------------------

Approach:

- First pass: count bulls and store unmatched secret chars
- Second pass: count cows using hashmap

---------------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    string getHint(string secret, string guess) {
        
        unordered_map<char, int> m;
        int bulls = 0, cows = 0;

        for(int i = 0; i < secret.size(); i++) {
            if(secret[i] == guess[i]) {
                bulls++;
            } else {
                m[secret[i]]++;
            }
        }

        for(int i = 0; i < secret.size(); i++) {
            if(secret[i] != guess[i] && m[guess[i]] > 0) {
                cows++;
                m[guess[i]]--;
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
