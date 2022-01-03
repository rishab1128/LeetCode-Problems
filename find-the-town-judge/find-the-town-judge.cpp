class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) 
    {
        vector<int>deg(n+1,0);
        unordered_map<int,int>mp;
        for(int i=0; i<trust.size(); i++)
        {
            int u=trust[i][0] , v=trust[i][1];
            mp[u]=1;
            deg[v]++;
        }
        for(int i=1; i<=n; i++)
        {
            if(deg[i]==n-1 and mp.find(i)==mp.end())
                return i;
        }
        return -1;
    }
};