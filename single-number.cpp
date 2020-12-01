#include<bits/stdc++.h>
using namespace std;
​
class Solution 
{
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    int singleNumber(vector<int>& nums) 
    {
        int res=0;
        for(auto x: nums)
            res^=x;
        return res;
    }
};
​
​
​
