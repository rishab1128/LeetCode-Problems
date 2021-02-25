class Solution {
public:
    Solution()
    {
        ios_base::sync_with_stdio(false);
        cout.tie(NULL);
        cin.tie(NULL);
    }
    
    int largestRectangleAreaInHistogram(vector<int>& hts) 
    {
        //Using only dp and no stack
        int n=hts.size();
        int maxi=0;
        int left[n],right[n];
        left[0]=-1,right[n-1]=n;
        for(int i=1; i<n; i++)
        {
            int j=i-1;
            while(j>=0&&hts[j]>=hts[i])
            {
                j=left[j];
            }
            left[i]=j;
        }
        for(int i=n-2; i>=0; i--)
        {
            int j=i+1;
            while(j<n&&hts[j]>=hts[i])
            {
                j=right[j];
            }
            right[i]=j;
        }
        for(int i=0; i<n; i++)
        {
            maxi=max(maxi,hts[i]*(right[i]-left[i]-1));
        }
        return maxi;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int m=matrix.size();
        if(m==0)
            return 0;
        int n=matrix[0].size(),maxi=0;
        vector<vector<int>>grid(m,vector<int>(n,0));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
                grid[i][j]=matrix[i][j]-'0';
        }
        vector<vector<int>>ht(m,vector<int>(n,0));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0||grid[i][j]==0)
                    ht[i][j]=grid[i][j];
                else
                    ht[i][j]=ht[i-1][j]+1;
            }
        }
        
        for(int i=0; i<m; i++)
        {
            maxi=max(maxi,largestRectangleAreaInHistogram(ht[i]));
        }
        
        return maxi;
        
    }
};