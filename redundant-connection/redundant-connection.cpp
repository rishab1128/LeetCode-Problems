class Solution {
public:
    //Returns the parent of x
    int par[1005];
    int find(int x)
    {
        if(x==par[x])
            return x;
        return find(par[x]);
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        int n=edges.size();
        
        //Initilaizing the parent array
        for(int i=0; i<=n; i++)
            par[i]=i;
        
        vector<int>ans(2,0);
        for(int i=0; i<n; i++)
        {
            int x=find(edges[i][0]),y=find(edges[i][1]);
            if(x!=y)
                par[y]=x;
            else
                ans[0]=edges[i][0],ans[1]=edges[i][1];
        }
        return ans;
    }
};