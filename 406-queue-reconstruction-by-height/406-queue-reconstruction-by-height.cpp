#include<bits/stdc++.h>
using namespace std;

bool sortinrev(const pair<int,int> &a, const pair<int,int> &b) 
{
    if(a.first==b.first)
        return a.second<b.second; 
    return (a.first > b.first); 
}

class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    void order(vector<vector<int>>& ans, int n, int pos, int x, int y)
    {
        for(int i=n-2; i>=pos; i--)
        {
            ans[i+1]=ans[i];
            ans[i].clear();
        }
        ans[pos].push_back(x);
        ans[pos].push_back(y);
    }

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        vector<pair<int,int>>v;
        int n=people.size();
        for(int i=0; i<n; i++)
        {
            v.push_back(make_pair(people[i][0],people[i][1]));
        }
        sort(v.begin(),v.end(),sortinrev);
        // for(auto x: v)
        //     cout<<x.first<<" "<<x.second<<endl;
        vector<vector<int>>ans(n);
        for(int i=0; i<n; i++)
        {
           int k=v[i].second;
           if(ans[k].size()==0)
           {
               ans[k].push_back(v[i].first);
               ans[k].push_back(v[i].second);
           }
           else if(ans[k].size()>0)
           {
               order(ans,n,k,v[i].first,v[i].second);
           }
        }
        // for(int i=0; i<n; i++)
        // {
        //     cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
        // }
        return ans;

    }
};