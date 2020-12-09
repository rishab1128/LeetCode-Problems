#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
​
class Solution 
{
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) 
    {
        priority_queue<pair<int,int>>pq;
        int n=points.size(),ans=INT_MIN;
        for(int i=0; i<n; i++)
        {
            int x=points[i][0];
            int y=points[i][1];
            while(!pq.empty()&&x-pq.top().second>k)
                pq.pop();
            if(!pq.empty())
                ans=max(ans,x+y+pq.top().first);
            pq.push(make_pair(y-x,x));
        }
        return ans;
    }
};
