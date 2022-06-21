class Solution {
public:
    
    int m;
    int dp[(1<<14)+1][8];
    
    int recur(vector<int>&arr, int mask, int op)
    {
        if(op>m/2)
            return 0;
        
        if(dp[mask][op]!=-1)
            return dp[mask][op];
        
        int ans = 0;
        for(int i=0; i<m; i++)
        {
            if((1<<i)&mask)
                continue;
            for(int j=i+1; j<m; j++)
            {
                if((1<<j)&mask)
                    continue;
                int newMask = (1<<i)+(1<<j)+mask;
                ans = max(ans , op*__gcd(arr[i],arr[j])+recur(arr,newMask,op+1));
            }
        }
        return dp[mask][op]=ans;
    }
    
    int maxScore(vector<int>& arr) 
    {
        memset(dp,-1,sizeof(dp));
        m = arr.size();
        int ans = recur(arr,0,1);
        return ans;
    }
};