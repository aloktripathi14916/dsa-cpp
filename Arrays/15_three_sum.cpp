/***********************************************************************
* LeetCode 15 - 3Sum
* 
* Problem: Given an integer array nums, return all unique triplets
* [nums[i], nums[j], nums[k]] such that i != j != k and 
* nums[i] + nums[j] + nums[k] == 0.
*
* This file contains three approaches:
* 1. Brute Force
* 2. Hashing
* 3. Two-Pointer (Optimal)
*
* Usage: Call any of the functions:
* - LC15_BruteForce(nums)
* - LC15_Hashing(nums)
* - LC15_TwoPointer(nums)
*
* Complexity:
* - Brute Force: O(n^3 * log(unique triplets)) time, O(n^3) space
* - Hashing: O(n^2 * log(unique triplets)) time, O(n^2) space
* - Two-Pointer: O(n^2) time, O(1) extra space
***********************************************************************/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

/***********************
 * Approach 1: Brute Force
 ***********************/
vector<vector<int>> LC15_BruteForce(vector<int>& nums) {
    int n = nums.size();
    set<vector<int>> uniqueTriplets;
    
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                if(nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> trip = {nums[i], nums[j], nums[k]};
                    sort(trip.begin(), trip.end());
                    uniqueTriplets.insert(trip); // automatically remove duplicates
                }
            }
        }
    }

    return vector<vector<int>>(uniqueTriplets.begin(), uniqueTriplets.end());
}

/***********************
 * Approach 2: Hashing
 ***********************/
vector<vector<int>> LC15_Hashing(vector<int>& nums) {
    int n = nums.size();
    set<vector<int>> uniqueTriplets;

    for(int i = 0; i < n; i++) {
        set<int> seen;
        for(int j = i + 1; j < n; j++) {
            int toFind = -nums[i] - nums[j];
            if(seen.find(toFind) != seen.end()) {
                vector<int> trip = {nums[i], nums[j], toFind};
                sort(trip.begin(), trip.end());
                uniqueTriplets.insert(trip);
            }
            seen.insert(nums[j]);
        }
    }

    return vector<vector<int>>(uniqueTriplets.begin(), uniqueTriplets.end());
}

/***********************
 * Approach 3: Two-Pointer (Optimal)
 ***********************/
vector<vector<int>> LC15_TwoPointer(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for(int i = 0; i < n; i++) {
        if(i > 0 && nums[i] == nums[i - 1]) continue; // skip duplicates for first number

        int st = i + 1, end = n - 1;
        while(st < end) {
            int sum = nums[i] + nums[st] + nums[end];

            if(sum == 0) {
                ans.push_back({nums[i], nums[st], nums[end]});

                // skip duplicates
                while(st < end && nums[st] == nums[st + 1]) st++;
                while(st < end && nums[end] == nums[end - 1]) end--;

                st++;
                end--;
            } else if(sum < 0) {
                st++;
            } else {
                end--;
            }
        }
    }

    return ans;
}

/***********************
 * Main Function
 ***********************/
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> v(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) cin >> v[i];

    cout << "\n--- Brute Force Triplets ---\n";
    for(auto &t : LC15_BruteForce(v))
        cout << t[0] << " " << t[1] << " " << t[2] << endl;

    cout << "\n--- Hashing Triplets ---\n";
    for(auto &t : LC15_Hashing(v))
        cout << t[0] << " " << t[1] << " " << t[2] << endl;

    cout << "\n--- Two-Pointer Triplets ---\n";
    for(auto &t : LC15_TwoPointer(v))
        cout << t[0] << " " << t[1] << " " << t[2] << endl;

    return 0;
}
