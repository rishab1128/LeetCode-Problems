class Solution {
public:
    bool check(int k , vector<vector<int>>&mat)
    {
        int m=mat.size() , n=mat[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<vector<int>>dir={{1,0} ,{-1,0} ,{0,1} ,{0,-1}};
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0][0]=1;
        while(!q.empty())
        {
            int x=q.front().first , y=q.front().second;
            q.pop();
            if(x==m-1 && y==n-1)
                return true;
            for(int i=0; i<4; i++)
            {
                int a=x+dir[i][0] , b=y+dir[i][1];
                if(a<m and b<n and a>=0 and b>=0 and !vis[a][b])
                {
                    if(abs(mat[x][y]-mat[a][b])<=k)
                    {
                        vis[a][b]=1;
                        q.push({a,b});
                    }
                }
            }
        }
        return false;
    }
    
    int minimumEffortPath(vector<vector<int>>& hts)
    {
        int m=hts.size() , n=hts[0].size();
        int low=0 , high=INT_MAX;
        int ans=-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(check(mid,hts))
            {
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};