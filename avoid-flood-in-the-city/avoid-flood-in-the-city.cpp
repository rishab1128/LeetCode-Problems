//Refer  : https://leetcode.com/problems/avoid-flood-in-the-city/discuss/697687/A-Set-and-A-Map-Lucid-code-with-documented-comments.

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) 
    {
        int n=rains.size();
        vector<int>ans(n);
        unordered_map<int,int>fullLakes; // Lake number -> day on which it became full.
        set<int> drydays;                // Set of available days that can be used for drying a full lake.
        for(int i=0; i<n; i++)
        {
            if(rains[i]==0)
            {
                drydays.insert(i);
                ans[i]=1;
            }
            else
            {
                int lake=rains[i];
                if(fullLakes.find(lake)!=fullLakes.end())
                {
                    auto it=drydays.upper_bound(fullLakes[lake]);
                    if(it==drydays.end())
                    {
                        return {};
                    }
                    int dryday=*it;
                    ans[dryday]=lake;
                    drydays.erase(dryday);
                }
                fullLakes[lake]=i;
                ans[i]=-1;
            }
        }
        return ans;
        
    }
};