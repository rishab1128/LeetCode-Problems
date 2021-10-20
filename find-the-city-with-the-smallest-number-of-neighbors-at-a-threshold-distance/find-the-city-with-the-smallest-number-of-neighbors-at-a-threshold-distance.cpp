class Solution {
public:
    const int INF=INT_MAX;
    
    //Using Floyd Warshall's Algo for All Pair Shortest Path
    
    int findTheCity(int n, vector<vector<int>>& edges, int thresh) 
    {
        vector<vector<int>>dist(n,vector<int>(n,INF));
        for(int i=0; i<n; i++)
            dist[i][i]=0;
        
        for(int i=0; i<edges.size(); i++)
        {
            int u=edges[i][0] , v=edges[i][1]  , w=edges[i][2];
            dist[u][v]=w;
            dist[v][u]=w;
        }
        
        for(int k=0; k<n; k++)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                {
                    if(dist[i][k]==INF || dist[k][j]==INF)
                        continue;
                    if(dist[i][k]+dist[k][j]<dist[i][j])
                        dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
        
        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<n; j++)
        //         cout<<dist[i][j]<<" ";
        //     cout<<endl;
        // }
        
        
        map<int,vector<int>>mp;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(dist[i][j]<=thresh)
                    mp[i].push_back(j);
            }
        }
        
        int sz=INF;
        int ans=-1;
        for(auto x: mp)
        {
            int key=x.first;
            //cout<<key<<"->";
            // for(auto ele : mp[key])
            //     cout<<ele<<" ";
            // cout<<endl;
            if(mp[key].size()<=sz)
            {
                sz=mp[key].size();
                ans=max(ans,key);
            }
        }
        
        return ans;
    }
};