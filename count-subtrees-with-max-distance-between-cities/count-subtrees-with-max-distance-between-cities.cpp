//Refer  : https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/discuss/891306/C%2B%2B-Explaination-with-comments

class Solution {
public:
    
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) 
    {
        //Floyd Warshall
        int INF=n; //Since it is a tree with n nodes the max distance b/w any two nodes can never be >= n
        vector<vector<int>>dist(n,vector<int>(n,INF));
        
        for(auto arr: edges)
        {
            int u=arr[0]-1 , v=arr[1]-1;
            dist[u][v]=1;
            dist[v][u]=1;
        }
        
        for(int k=0; k<n; k++)
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<n; j++)
                    dist[i][j]=min(dist[i][j] , dist[i][k]+dist[k][j]);
            }
        }
        
        //Iterating over all subsets and check if that subset is a subtree (no. of edges= no.of nodes in subtree-1)         //For a particular subtree also find the max distance b/w any two nodes
        
        vector<int>ans(n-1,0);
        
        for(int sub=0; sub<(1<<n); sub++)
        {
            int nodes=__builtin_popcount(sub);
            int edges=0;
            int maxDist=0;
            for(int i=0; i<n; i++)
            {
                if(sub&(1<<i))
                {
                    for(int j=i+1; j<n; j++)
                    {
                        if(sub&(1<<j))
                        {
                            edges+=dist[i][j]==1;
                            maxDist=max(maxDist , dist[i][j]);
                        }
                    }
                }
            }
            
            if(edges==nodes-1 and maxDist>0)
                ans[maxDist-1]++;
        }
        
        
        return ans;
    }
};