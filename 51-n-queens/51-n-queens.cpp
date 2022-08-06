class Solution {
public:
    
    bool isPossible(vector<string>&board, int row, int col, int n)
    {
        //Check upper col
        for(int i=row-1; i>=0; i--)
        {
            if(board[i][col]=='Q')
                return false;
        }
        
        //Check upper left diag
        for(int i=row-1 ,  j = col-1 ; i>=0 and j>=0 ; i--,j--)
        {
            if(board[i][j]=='Q')
                return false;
        }
        
        //Check upper right diag
        for(int i=row-1 ,  j = col+1 ; i>=0 and j<n ; i--,j++)
        {
            if(board[i][j]=='Q')
                return false;
        }
        
        return true;
    }
    
    void recur(vector<vector<string>>&ans, vector<string>&board, int row, int n)
    {
        if(row==n)
        {
            ans.push_back(board);
            return;
        }
        for(int col=0; col<n; col++)
        {
            if(isPossible(board,row,col,n))
            {
                board[row][col] = 'Q';
                recur(ans,board,row+1,n);
                board[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>>ans;
        string s(n,'.');
        vector<string>board(n,s);
        
        recur(ans,board,0,n);
        
        return ans;
    }
};