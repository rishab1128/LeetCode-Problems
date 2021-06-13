class Solution {
public:
    int n,m;
    
    vector<vector<int>>flip(vector<vector<int>>& mat, int x, int y) {
        mat[x][y] ^= 1;
        if(y - 1 >= 0) mat[x][y-1] ^= 1;
        if(y + 1 <  m) mat[x][y+1]^= 1;
        if(x - 1 >= 0) mat[x-1][y] ^= 1;
        if(x + 1 <  n) mat[x+1][y] ^= 1;
        return mat;
    }

    bool isZeroMat(vector<vector<int>>& mat) {
        for(auto i = 0; i < n; ++i)
            for(auto j = 0; j < m; ++j)
                if(mat[i][j])
                    return false;
        return true;
    }
    
    int func(vector<vector<int>>mat, int x, int y)
    {
        if(x==n)
            y++,x=0;
        if(y==m)
            return isZeroMat(mat)?0:10000;
        
        int op1=func(mat,x+1,y);
        int op2=func(flip(mat,x,y),x+1,y)+1;
        
        return min(op1,op2);
    }
    
    int minFlips(vector<vector<int>>& mat) 
    {
        n=mat.size(),m=mat[0].size();
        int ans=func(mat,0,0);
        if(ans>=10000)
            return -1;
        return ans;
    }
};