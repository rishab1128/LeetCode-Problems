class Solution {
public:
    void dfs(vector<vector<char>>& matrix, int i, int j)
    {
        int m = matrix.size(), n = matrix[0].size();
        if (i < 0 || i == m || j < 0 || j == n || matrix[i][j] == '0') 
        {
            return;
        }
        matrix[i][j] = '0';
        dfs(matrix, i - 1, j);
        dfs(matrix, i + 1, j);
        dfs(matrix, i, j - 1);
        dfs(matrix, i, j + 1);
    }
    
    int numIslands(vector<vector<char>>& grid) 
    {
        int m=grid.size(),n=grid[0].size(),ans=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]=='1')
                {
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};