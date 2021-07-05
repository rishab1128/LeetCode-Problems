class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) 
    {
        int m=mat.size() , n=mat[0].size() ;
        if(m*n!=r*c)
            return mat;
        
        vector<vector<int>>ans(r,vector<int>(c));
        int x=0,y=0;
        for(int i=0; i<r; i++)
        {
            if(x==m and y==n)
                    break;
            for(int j=0; j<c; j++)
            {
                if(x<m and y<n)
                {
                    ans[i][j]=mat[x][y];
                    y++;
                }
                if(x<m and y==n)
                {
                    x++;
                    y=0;
                }
                   
            }
        }
        return ans;
        
    }
};