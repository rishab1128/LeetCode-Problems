class Solution {
public:
    
    bool isPossible(vector<vector<char>>& board, int row, int col, char ch)
    {
        //Check in the same row
        for(int j=0; j<9; j++)
        {
            if(board[row][j]==ch)
                return false;
        }
        
        //Check in the same column
        for(int i=0; i<9; i++)
        {
            if(board[i][col]==ch)
                return false;
        }
        
        //Check in the same grid
        int rowFactor = row-(row%3);
        int colFactor = col-(col%3);
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                if(board[i+rowFactor][j+colFactor]==ch)
                    return false;
            }
        }
        
        return true;
    }
    
    bool FindEmptyLoc(vector<vector<char>>& board, int&row, int&col)
    {
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(board[i][j]=='.')
                {
                    row=i;
                    col=j;
                    return true;
                }
            }
        }
        return false;
    }
    
    bool recur(vector<vector<char>>& board)
    {
        int row,col;
        if(!FindEmptyLoc(board,row,col))
            return true;
        
        
        for(char ch='1'; ch<='9'; ch++)
        {
            char original = board[row][col];
            if(isPossible(board,row,col,ch))
            {
                board[row][col] = ch;
                if(recur(board))
                    return true;
                board[row][col] = original;
            }
        }
        
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) 
    {
        recur(board);
    }
};