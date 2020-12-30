#include<bits/stdc++.h>
using namespace std;
​
class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    int func(int*arr,int S,int sum,int n)
    {
        if(n==0&&sum==S)
        {
            return 1;
        }
        if(n<=0&&sum!=S)
            return 0;
        int left=func(arr+1,S,sum+arr[0],n-1);
        int right=func(arr+1,S,sum-arr[0],n-1);
        return left+right;
    }
​
    int findTargetSumWays(vector<int>& nums, int S) 
    {
        int n=nums.size();
        int arr[n];
        int ct=0;
        for(int i=0; i<n; i++)
            arr[i]=nums[i];
        int sum=0;
        ct=func(arr,S,sum,n);
        return ct;
    }
};
​
