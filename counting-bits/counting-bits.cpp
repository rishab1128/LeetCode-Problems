#include<bits/stdc++.h>
using namespace std;
​
class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    vector<int> countBits(int num) 
    {
        vector<int>ans(num+1);
        ans[0]=0;
        for(int i=1; i<=num; i++)
        {
            double x=log2(i);
            if(ceil(x)==floor(x))
                ans[i]=1;
            else
            {
                int t=floor(x);
                int a=pow(2,t);
                int b=i-a;
                ans[i]=ans[a]+ans[b];
            }
        }
        return ans;
        
    }
};
