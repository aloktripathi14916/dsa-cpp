// Problem: Two Sum
// Platform: LeetCode
// Topic: Arrays / Hashmap
// Time Complexity: O(n)  

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++){
            int complement = target - nums[i];

            if(mp.count(complement))
                return {mp[complement], i};

            mp[nums[i]] = i;
        }

        return {};
    }
};


//Method2: Brute force
//Time complexity: O(nsquare)

#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Number of elements:";
    cin>>n;int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int t;
    cout<<"Target:";
    cin>>t;
    for(int i=0;i<n;i++)
    {
        
        for(int j=i+1;j<n;j++)
        {
            
            if(arr[i]+arr[j]==t) {
                 cout<<"("<<i<<","<<j<<")";
              
                 return 0;;
            }
           
        }
    }
   
}
