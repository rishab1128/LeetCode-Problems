class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& arr) 
    {
        int n=arr.size();
        if(arr[0][0] || arr[n-1][n-1])
            return -1;
        
        queue<pair<int,int>>q;
        vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1}};
        
        q.push({0,0});
        arr[0][0]=1;
        int ct=1;
        
        while(q.size()>0)
        {
            int sz=q.size();
            while(sz--)
            {
                int x=q.front().first , y=q.front().second;
                q.pop();
                if(x==n-1 and y==n-1)
                    return ct;
                
                for(int i=0; i<8; i++)
                {
                    int dx=x+dir[i][0] , dy=y+dir[i][1];
                    if(dx>=0 and dx<n and dy>=0 and dy<n and arr[dx][dy]==0)
                    {
                        q.push({dx,dy});
                        arr[dx][dy]=1;
                    }
                }
            }
            if(q.size()>0)
                ct++;
        }
        return -1;
    }
};