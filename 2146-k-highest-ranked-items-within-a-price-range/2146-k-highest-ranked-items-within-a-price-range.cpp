class Solution {
public:
    
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& arr, vector<int>& price, vector<int>& start, int k) 
    {
        int n=arr.size(), m=arr[0].size() , low=price[0], high=price[1] , x=start[0], y=start[1];
        
        
        vector<vector<int>>pos;
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dis(n,vector<int>(m,0));
        vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        queue<vector<int>>q;
        
        q.push({x,y,0});
        vis[x][y]=1;
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            int x=node[0],y=node[1],distance=node[2];
            
            if(arr[x][y]>=low and arr[x][y]<=high)
                pos.push_back({distance,arr[x][y],x,y});
            
            dis[x][y]=distance;
            for(int i=0; i<4; i++)
            {
                int dx=x+dir[i][0] , dy=y+dir[i][1];
                if(dx>=0 and dx<n and dy>=0 and dy<m and !vis[dx][dy] and arr[dx][dy])
                {
                    vis[dx][dy]=1;
                    q.push({dx,dy,distance+1});
                }
            }
        }
        
        sort(pos.begin(),pos.end());
        
        vector<vector<int>>ans;
        for(int i=0; i<min(k,(int)pos.size()); i++)
            ans.push_back({pos[i][2], pos[i][3]});
        
        
        return ans;
        
    }
};