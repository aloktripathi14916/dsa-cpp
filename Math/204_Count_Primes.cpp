/*
Problem: Count Primes
Platform: LeetCode (LC 204)
Topic: Math / Sieve of Eratosthenes

Given an integer n, return the number of prime numbers
that are strictly less than n.

---------------------------------------------------------

Approach: Sieve of Eratosthenes

1. Create a boolean array `isPrime` of size n, initialized to true.
2. Mark 0 and 1 as non-prime.
3. For each number i from 2 to sqrt(n):
    - If i is prime, mark all multiples of i as non-prime.
4. Count all remaining true values.

---------------------------------------------------------

Time Complexity: O(n log log n)
Space Complexity: O(n)

Example:
Input: n = 10
Output: 4
Explanation: Primes are [2,3,5,7]
*/

class Solution {
public:
    int countPrimes(int n) {

        if(n <= 2) return 0;

        vector<bool> isPrime(n, true);

        isPrime[0] = false;
        isPrime[1] = false;

        // Sieve process
        for(int i = 2; i * i < n; i++) {
            if(isPrime[i]) {
                for(int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Count primes
        int count = 0;
        for(int i = 2; i < n; i++) {
            if(isPrime[i])
                count++;
        }

        return count;
    }
};
