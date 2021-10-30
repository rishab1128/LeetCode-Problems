class Solution {
public:
    void solve(vector<vector<char>>& board) 
    {
        int n=board.size() , m=board[0].size();
        queue<pair<int,int>>q;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(i==0 || i==n-1 || j==0 || j==m-1)
                {
                    if(board[i][j]=='O')
                    {
                        board[i][j]='1';
                        q.push({i,j});
                    }
                }
            }
        }
        vector<vector<int>>dir={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty())
        {
            int x=q.front().first,y=q.front().second;
            q.pop();
            for(int i=0; i<4; i++)
            {
                int a=x+dir[i][0],b=y+dir[i][1];
                if(a>=0 and a<n and b>=0 and b<m and board[a][b]=='O')
                {
                    board[a][b]='1';
                    q.push({a,b});
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j]=='O')
                    board[i][j]='X';
                else if(board[i][j]=='1')
                    board[i][j]='O';
            }
        }
        
        return;
    }
};