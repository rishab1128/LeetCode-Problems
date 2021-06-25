class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) 
    {
        int n=mat.size() , m=mat[0].size();
        set<int>rows,cols;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j]==0)
                {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        
        for(auto i:rows)
        {
            for(int j=0; j<m; j++)
                mat[i][j]=0;
        }
        
        for(auto j:cols)
        {
            for(int i=0; i<n; i++)
                mat[i][j]=0;
        }
        
        
        
        
    }
};