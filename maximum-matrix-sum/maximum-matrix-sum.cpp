class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& mat) 
    {
        int n=mat.size() , m=mat[0].size();
        long long neg=0 , mini=LLONG_MAX , sum=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j]<0)
                    neg++;
                if(abs(mat[i][j])<mini)
                    mini=abs(mat[i][j]);
                sum+=abs(mat[i][j]);
            }
        }
        if(neg%2==0)
            return sum;
        
        return sum-2*mini;
    }
};