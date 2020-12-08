#include<bits/stdc++.h>
using namespace std;
​
class Solution {
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    int maxPoints(vector<vector<int>>& points) 
    {
        if((int)points.size()<=2)
            return (int)points.size();
        vector<pair<int,int>>pts;
        int ans=0;
        for(int i=0; i<(int)points.size(); i++)
        {
            pts.push_back({points[i][0],points[i][1]});
        }
        for(int i=0; i<(int)pts.size(); i++)
        {
            unordered_map<string,int>mp;
            int dup=1;
            for(int j=i+1; j<(int)pts.size(); j++)
            {
                if(pts[i].first==pts[j].first&&pts[i].second==pts[j].second)
                {
                    dup++;
                }
                else
                {
                    int dx=pts[j].first-pts[i].first;
                    int dy=pts[j].second-pts[i].second;
                    int g=__gcd(dx,dy);
                    dx=dx/g;
                    dy=dy/g;
                    mp[to_string(dy)+'/'+to_string(dx)]++;
                }
            }
            ans=max(ans,dup);
            for(auto x: mp)
            {
                ans=max(ans,x.second+dup);
                //cout<<x.first<<" "<<x.second<<endl;
            }
                
        }
        return ans;
    }
};
