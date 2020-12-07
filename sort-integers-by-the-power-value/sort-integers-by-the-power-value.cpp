#include<bits/stdc++.h>
using namespace std;
​
bool comp(const pair<int,int> &a, const pair<int,int> &b) 
{ 
    return (a.second<b.second); 
}
​
class Solution {
public:
​
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
​
    unordered_map<int,int>dp;
    int power_val(int x)
    {
        if(dp[x]||x==1)
            return dp[x];
        
        if(x%2)
            dp[x]=1+power_val(3*x+1);
        else
            dp[x]=1+power_val(x/2);
          
        return dp[x];
    }
​
    int getKth(int lo, int hi, int k) 
    {
        vector<pair<int,int>>ans;
        for(int i=lo; i<=hi; i++)
        {
            ans.push_back({power_val(i),i});
        }
        sort(ans.begin(),ans.end());
        return ans[k-1].second;
    }
};
