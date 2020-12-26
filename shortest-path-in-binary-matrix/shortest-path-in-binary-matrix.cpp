                int dy=y+dir.second;
                if(dx<n&&dx>=0&&dy<n&&dy>=0&&grid[dx][dy]==0)
                {
                    grid[dx][dy]=grid[x][y]+1;
                    q.push(make_pair(dx,dy));
                }
                    
            }
        }
        
        return -1;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        if(grid[0][0]||grid[n-1][n-1])
            return -1;
        int ans=bfs(grid,n);
        return ans;
    }
};
​
