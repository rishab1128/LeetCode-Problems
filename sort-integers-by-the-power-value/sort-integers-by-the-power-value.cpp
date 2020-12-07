#include<bits/stdc++.h>
using namespace std;
​
class Solution {
public:
​
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
​
    // bool comp(const pair<int,int> &a, const pair<int,int> &b) 
    // { 
    //     return (a.second<b.second); 
    // }
​
    int power_val(int x)
    {
        int ct=0;
        while(x!=1)
        {
            if(x%2==0)
                x/=2;
            else
                x=3*x+1;
            ct++;
        }
        return ct;
    }
​
    int getKth(int lo, int hi, int k) 
    {
        vector<pair<int,int>>ans;
        for(int i=lo; i<=hi; i++)
        {
            int x=power_val(i);
            ans.push_back({x,i});
        }
        sort(ans.begin(),ans.end());
        return ans[k-1].second;
    }
};
