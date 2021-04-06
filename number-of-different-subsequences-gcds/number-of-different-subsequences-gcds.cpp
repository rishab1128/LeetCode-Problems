#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countDifferentSubsequenceGCDs(vector<int>& nums) 
    {
        const int sz=200001;
        vector<bool>arr(sz);
        for(auto x: nums)
            arr[x]=1;
        int ans=0;
        for(int i=1; i<sz; i++)
        {
            int hcf=0;
            for(int j=i; j<sz; j+=i)
            {
                if(hcf==i)
                    break;
                if(arr[j])
                    hcf=__gcd(j,hcf);
            }
            if(hcf==i)
                ans++;
        }
        return ans;
        
    }
};