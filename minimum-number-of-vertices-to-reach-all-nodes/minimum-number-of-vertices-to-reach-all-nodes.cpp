#include<bits/stdc++.h>
using namespace std;
​
class Solution {
public:
    //vector<int>adj[1000005];
    //int vis[1000005];
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) 
    {
        int m=edges.size();
        vector<int>indeg(n,0);
        vector<int>ans;
        //memset(vis,0,sizeof(vis));
        for(int i=0; i<m; i++)
        {
            int x=edges[i][0];
            int y=edges[i][1];
            //adj[x].push_back(y);
            indeg[y]++;
        }
        for(int i=0; i<n; i++)
        {
            if(!indeg[i])
                ans.push_back(i);
        }
        return ans;
    }
};
