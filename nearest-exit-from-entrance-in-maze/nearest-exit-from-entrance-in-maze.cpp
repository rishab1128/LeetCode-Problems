class Solution {
public:
    int n,m;
    bool isValid(int x, int y)
    {
        if(x<n and y<m and x>=0 and y>=0)
            return true;
        return false;
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& ent) 
    {
        n=maze.size() , m=maze[0].size();
        queue<pair<pair<int,int>, int>>q;
        q.push({{ent[0],ent[1]},0});
        
        
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        vis[ent[0]][ent[1]]=1;
        
        
        vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
        
        
        while(q.size()>0)
        {
            int t=q.size() ;
            for(int z=0; z<t; z++)
            {
                
                int i=q.front().first.first , j=q.front().first.second;
                int ct=q.front().second;
                q.pop();


                for(int l=0;l<4;l++)
                {
                    int x=i+dir[l][0];
                    int y=j+dir[l][1];
					
                    if(!isValid(x,y) || maze[x][y]=='+' || vis[x][y])
                        continue;
					
                    //cout<<x<<" "<<y<<" "<<ct<<endl;
                    if(x==0 || y==0 || x==n-1 || y==m-1)
                        return ct+1;
					
                    vis[x][y]=1;
                    q.push({{x,y},ct+1});
                }
            }
            
        }
        
        
        return -1;
        
    }
};