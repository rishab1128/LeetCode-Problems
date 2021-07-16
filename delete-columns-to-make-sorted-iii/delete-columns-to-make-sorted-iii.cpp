class Solution {
public:
    //Idea similar to LIS 
    int minDeletionSize(vector<string>& strs) 
    {
        int m=strs[0].size()  , n=strs.size();
        vector<int>dp(m,1);
        //dp[j] --> Longest increasing subseq till j taking into consideration all the strings (strs[0] to strs[n-1]);
        for(int j=1; j<m; j++)
        {
            for(int k=j-1; k>=0; k--)
            {
                int flag=1;
                for(int i=0; i<n; i++)
                {
                    if(strs[i][j]>=strs[i][k])
                        continue;
                    else
                    {    
                        flag=0;
                        break;
                    }
                }
                if(flag)
                    dp[j]=max({dp[j],dp[k]+1,1});
            }
        }
        
        // for(auto x: dp)
        //     cout<<x<<" ";
        // cout<<endl;
        
        int lis=*max_element(dp.begin(),dp.end());
        return m-lis;
    }
};