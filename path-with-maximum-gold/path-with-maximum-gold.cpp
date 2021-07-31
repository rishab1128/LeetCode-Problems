class Solution {
public:
    int n,m;
    int dfs(vector<vector<int>>&mat,int start_x, int start_y)
    {
        int op1=0,op2=0,op3=0,op4=0;
        int tmp=mat[start_x][start_y];
        mat[start_x][start_y]=0;
        if(start_x+1<n and mat[start_x+1][start_y]>0)
        {
            op1=dfs(mat,start_x+1,start_y);
        }
        if(start_x-1>=0 and mat[start_x-1][start_y]>0)
        {
            op2=dfs(mat,start_x-1,start_y);
        }
        if(start_y+1<m and mat[start_x][start_y+1]>0)
        {
            op3=dfs(mat,start_x,start_y+1);
        }
        if(start_y-1>=0 and mat[start_x][start_y-1]>0)
        {
            op4=dfs(mat,start_x,start_y-1);
        }

        mat[start_x][start_y]=tmp;
        
        return mat[start_x][start_y]+max({op1,op2,op3,op4});
    }

    int getMaximumGold(vector<vector<int>>& mat) 
    {
        int ans=0;
        n=mat.size() , m=mat[0].size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j]>0)
                {
                    ans=max(ans,dfs(mat,i,j));
                }
            }
        }
        return ans;
    }

};
