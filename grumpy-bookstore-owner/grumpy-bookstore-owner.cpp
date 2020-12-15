#include<bits/stdc++.h>
using namespace std;
​
class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) 
    {
        int n=customers.size();
        int suff[n+1];
        memset(suff,0,sizeof(suff));
        if(!grumpy[n-1])
            suff[n-1]=customers[n-1];
        for(int i=n-2; i>=0; i--)
        {
            if(grumpy[i])
                suff[i]=suff[i+1];
            else
                suff[i]=customers[i]+suff[i+1];
        }
        int start=0,end=0,tot=0,maxi=0;
        for(;end<X; end++)
        {
            tot+=customers[end];
        }
        maxi=max(maxi,tot+suff[end]);
        while(end<n)
        {
            tot+=customers[end];
            if(grumpy[start])
                tot-=customers[start];
            maxi=max(maxi,tot+suff[end+1]);
            start++;
            end++;
        }
        return maxi;
        
    }
};
​
