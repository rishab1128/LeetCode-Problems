class Solution {
public:
    void recur(vector<vector<string>>&ans, vector<string>&board, vector<bool>&up , vector<bool>&upperLeftDiag, vector<bool>&upperRightDiag, int row, int n)
    {
        if(row==n)
        {
            ans.push_back(board);
            return;
        }
        for(int col=0; col<n; col++)
        {
            if(!up[col] and !upperLeftDiag[n-1+col-row] and !upperRightDiag[col+row])
            {
                board[row][col] = 'Q';
                up[col] = 1;
                upperLeftDiag[n-1+col-row] = 1;
                upperRightDiag[col+row] = 1;
                
                recur(ans,board,up,upperLeftDiag,upperRightDiag,row+1,n);
                
                board[row][col] = '.';
                up[col] = 0;
                upperLeftDiag[n-1+col-row] = 0;
                upperRightDiag[col+row] = 0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>>ans;
        string s(n,'.');
        vector<string>board(n,s);
        
        vector<bool>up(n,0) , upperLeftDiag(2*n-1,0) , upperRightDiag(2*n-1,0);
        
        recur(ans,board,up,upperLeftDiag,upperRightDiag,0,n);
        
        return ans;
    }
};