class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) 
    {
        int n = grid.size() , m = grid[0].size();
        vector<int>colMax(m) , rowMax(n);
        int ans = 0;
        
        for(int col = 0 ; col < m; col++)
        {
            int maxi = -1;
            for(int row = 0; row < n; row++)
                maxi = max(maxi,grid[row][col]);
            colMax[col] = maxi;
        }
        
        for(int row = 0 ; row < n; row++)
        {
            int maxi = -1;
            for(int col = 0; col < m; col++)
                maxi = max(maxi,grid[row][col]);
            rowMax[row] = maxi;
        }
        
        for(int row = 0; row < n; row++)
        {
            for(int col = 0; col < m; col++)
            {
                int newMaxi = min(rowMax[row],colMax[col]);
                int add = newMaxi - grid[row][col];
                ans+=add;
            }
        }
        
        return ans;
        
        
    }
};