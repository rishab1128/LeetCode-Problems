class Solution {
public:
    
    bool isValid(vector<vector<int>>&arr)
    {
        if(arr[1][2]!=0)
            return false;
        
        for(int j=0; j<3; j++)
        {
            if(arr[0][j]!=j+1)
                return false;
        }
        
        int k=4;
        for(int j=0; j<2; j++)
        {
            if(arr[1][j]!=k)
                return false;
            k++;
        }
        
        return true;
    }
    
    int slidingPuzzle(vector<vector<int>>& arr) 
    {
        int n = 2, m=3;
        
        vector<vector<int>>dir = {{0,1},{0,-1},{1,0},{-1,0}};
        map<vector<vector<int>> , int>vis;
        queue<vector<vector<int>>>q;
        
        q.push(arr);
        vis[arr]=1;
        int steps = 0;
        
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto vec = q.front();
                q.pop();
                
                if(isValid(vec))
                    return steps;
                
                int x = -1 , y = -1;
                for(int i=0; i<2; i++)
                {
                    for(int j=0; j<3; j++)
                    {
                        if(!vec[i][j])
                        {
                            x=i;
                            y=j;
                            break;
                        }
                    }
                    if(x!=-1 and y!=-1)
                        break;
                }

                for(int i=0; i<4; i++)
                {
                    int dx = x+dir[i][0] , dy = y+dir[i][1];
                    if(dx<0 || dx>=n || dy<0 || dy>=m)
                        continue;
                    auto newVec = vec;
                    swap(newVec[x][y],newVec[dx][dy]);
                    if(!vis[newVec])
                    {
                        vis[newVec]=1;
                        q.push(newVec);
                    }
                }
            }
            steps++;
        }
        
        return -1;
    }
};