class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines)
    {
        set<pair<int,int>>st;
        for(auto x: mines)
        {
            st.insert({x[0],x[1]});
        }
        
        vector<vector<int>>arr(n,vector<int>(n,1));
        int ans=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(st.count({i,j}))
                    arr[i][j]=0;
                
                if( (i==0 || i==n-1 || j==0 || j==n-1 ) and arr[i][j] )
                    ans=1;
            }
        }
        
        
        int t2b[n][n],b2t[n][n],l2r[n][n],r2l[n][n];
        
        //Filling table Top to Bottom(t2b)
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0)
                    t2b[i][j]=arr[i][j];
                else
                    t2b[i][j]= arr[i][j]==0 ? 0 : arr[i][j]+t2b[i-1][j];
            }
        }
        
        //Filling table Bottom to Top(b2t)
        for(int i=n-1; i>=0; i--)
        {
            for(int j=0; j<n; j++)
            {
                if(i==n-1)
                    b2t[i][j]=arr[i][j];
                else
                    b2t[i][j]= arr[i][j]==0 ? 0 : arr[i][j]+b2t[i+1][j];
            }
        }
        
        //Filling table Left To Right(l2r)
        for(int j=0; j<n; j++)
        {
            for(int i=0; i<n; i++)
            {
                if(j==0)
                    l2r[i][j]=arr[i][j];
                else
                    l2r[i][j]= arr[i][j]==0 ? 0 : arr[i][j]+l2r[i][j-1];
            }
        }
        
        //Filling table Right to Left(r2l)
        for(int j=n-1; j>=0; j--)
        {
            for(int i=0; i<n; i++)
            {
                if(j==n-1)
                    r2l[i][j]=arr[i][j];
                else
                    r2l[i][j]= arr[i][j]==0 ? 0 : arr[i][j]+r2l[i][j+1];
            }
        }
        
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i>0 and i<n-1 and j>0 and j<n-1 and arr[i][j])
                {
                    int mini=min({ t2b[i-1][j]  , b2t[i+1][j] , l2r[i][j-1] , r2l[i][j+1] } );
                    ans=max(ans,mini+1);
                }
            }
        }
        
        return ans;
        
    }
};