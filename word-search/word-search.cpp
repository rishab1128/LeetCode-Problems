class Solution {
public:
    int n,m;
    bool recur(vector<vector<char>>&board , string&word , int i, int j, int k)
    {
        //Base Case
        if(k==word.size())
            return true;
        
        if(i<0 || i>=n || j<0 || j>=m || board[i][j]!=word[k])
            return false;
        
        char ch=board[i][j];
        board[i][j]='*'; //mark the cell
        
        bool ans=(recur(board,word,i+1,j,k+1) || recur(board,word,i-1,j,k+1) || recur(board,word,i,j+1,k+1) || recur(board,word,i,j-1,k+1));
        
        board[i][j]=ch; //unmark the cell - backtrack
        
        return ans;
        
    }
    
    bool exist(vector<vector<char>>& board, string word)
    {
        n=board.size() , m=board[0].size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(recur(board,word,i,j,0))
                    return true;
            }
        }
        return false;
    }
};