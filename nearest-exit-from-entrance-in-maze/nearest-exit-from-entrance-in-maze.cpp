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
        queue<pair<int,int>>q;
        q.push({ent[0],ent[1]});
        
        
        maze[ent[0]][ent[1]]='+';
        
        
        vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
        int ct=1;
        
        while(q.size()>0)
        {
            int t=q.size() ;
            
            for(int z=0; z<t; z++)
            {
                
                int i=q.front().first , j=q.front().second;
                q.pop();


                for(int l=0;l<4;l++)
                {
                    int x=i+dir[l][0];
                    int y=j+dir[l][1];
					
                    if(!isValid(x,y) || maze[x][y]=='+')
                        continue;
					
                    if(x==0 || y==0 || x==n-1 || y==m-1)
                        return ct;
					
                    maze[x][y]='+';
                    q.push({x,y});
                }
                
            }
            
            ct++;
            
        }
        
        
        return -1;
        
    }
};