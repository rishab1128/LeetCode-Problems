class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) 
    {
        int n=mat.size() , m=mat[0].size();
        int pref[n][m];
        
        pref[0][0]=mat[0][0];
        
        //Fill 1st row
        for(int j=1; j<m; j++)
            pref[0][j]=pref[0][j-1]+mat[0][j];
        
        //Fill 1st col
        for(int i=1; i<n; i++)
            pref[i][0]=pref[i-1][0]+mat[i][0];
        
        //Fill rest of the table
        for(int i=1; i<n; i++)
        {
            for(int j=1; j<m; j++)
                pref[i][j]=pref[i-1][j]+pref[i][j-1]+mat[i][j]-pref[i-1][j-1];
        }
        
        // for(int i=0; i<n; i++)
        // {
        //     for(int j=0; j<m; j++)
        //         cout<<pref[i][j]<<" ";
        //     cout<<endl;
        // }
        
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i=0; i<n; i++)
        {
            int r_min=max(0,i-k);
            int r_max=min(n-1,i+k);
            int height=r_max-r_min;
            
            for(int j=0; j<m; j++)
            {
                int c_min=max(0,j-k);
                int c_max=min(m-1,j+k);
                int width=c_max-c_min;
                int res=0;
                
                pair<int,int> p1={r_min , c_min};
                pair<int,int> p2={r_min , c_min+width};
                pair<int,int> p3={r_min+height , c_min};
                
                if(p2.first-1>=0 and p3.second-1>=0 )
                    res=pref[r_max][c_max] - pref[p2.first-1][p2.second] - pref[p3.first][p3.second-1] + pref[p1.first-1][p1.second-1];
                
                else if(p2.first-1<0 and p3.second-1>=0 )
                    res=pref[r_max][c_max]  - pref[p3.first][p3.second-1] ;
                
                else if(p2.first-1>=0 and p3.second-1<0 )
                    res=pref[r_max][c_max] - pref[p2.first-1][p2.second] ;
                else
                    res=pref[r_max][c_max];
                
                ans[i][j]=res;
            }
        }
        
        return ans;
    }
};