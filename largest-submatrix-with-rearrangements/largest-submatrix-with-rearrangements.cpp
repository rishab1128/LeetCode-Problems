public:
    int rearr(vector<int>v)
    {
        sort(v.begin(),v.end());
        int n=v.size();
        int j=n,ans=0;
        for(int i=0; i<n; i++)
        {
            ans=max(ans,v[i]*j);
            j--;
        }
        return ans;
    }
    int largestSubmatrix(vector<vector<int>>& matrix) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        int height[m][n];
        vector<int>v;
        int ans=0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0)
                {
                    if(matrix[i][j])
                        height[i][j]=1;
                    else
                        height[i][j]=0;
                    v.push_back(height[i][j]);
                }
                else
                {
                    if(matrix[i][j])
                        height[i][j]=height[i-1][j]+1;
                    else
                        height[i][j]=0;
                    v.push_back(height[i][j]);
                }
            }
            ans=max(ans,rearr(v));
            v.clear();
        }
        return ans;
    }
};
