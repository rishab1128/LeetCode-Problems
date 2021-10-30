class Solution {
public:
    //O(1) memory (without the recursion stack) but modifying the values in the board
    int n,m;
    vector<vector<int>>dir;
    void dfs(int i, int j, vector<vector<char>>&arr)
    {
        arr[i][j]='.';
        for(int k=0; k<4; k++)
        {
            int x=i+dir[k][0] , y=j+dir[k][1];
            if(x>=0 and x<n and y>=0 and y<m and arr[x][y]=='X')
                dfs(x,y,arr);
        }
    }
    
    int countBattleships(vector<vector<char>>& board) 
    {
        n=board.size() , m=board[0].size();
        dir={ {1,0} ,{-1,0} , {0,1} , {0,-1}};
        int ans=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(board[i][j]=='X')
                {
                    ans++;
                    dfs(i,j,board);
                }
            }
        }
        return ans;
        
    }
};