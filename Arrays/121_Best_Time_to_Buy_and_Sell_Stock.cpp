/*
Problem: Best Time to Buy and Sell Stock
Platform: LeetCode (LC 121)
Topic: Arrays / Greedy

You are given an array prices where prices[i] is the price of a given
stock on the ith day. You want to maximize your profit by choosing
a single day to buy and a different day to sell.

Return the maximum profit you can achieve. If no profit can be made, return 0.

Approach:
- Keep track of the minimum price seen so far.
- Calculate profit if selling today: profit = prices[i] - minSoFar
- Update maxProfit if this profit is higher.
- Update minSoFar if current price is lower.

Time Complexity: O(n)
Space Complexity: O(1)

Example:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 5.
*/

class Solution {
public:
    int maxProfit(vector<int>& v) {

        int minSoFar = v[0];
        int maxProfit = 0;

        for (int i = 1; i < v.size(); i++) {
            int profit = v[i] - minSoFar;

            if (profit > maxProfit)
                maxProfit = profit;

            if (v[i] < minSoFar)
                minSoFar = v[i];
        }

        return maxProfit;  // returns 0 if no profit possible
    }
};
