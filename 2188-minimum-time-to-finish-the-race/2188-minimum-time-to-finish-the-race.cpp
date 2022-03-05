using ll = long long;
class Solution {
public:
    
    int minimumFinishTime(vector<vector<int>>& tires, int cT, int laps) 
    {
        int n=tires.size();
        vector<ll>dp(laps+1,LLONG_MAX);
        //dp[i] := min time to cover i laps
        
        //1) First fill the dp array s.t we have no option to change tires
        dp[0]=0;
        for(int i=0; i<n; i++)
        {
            
            ll f=tires[i][0] , r=tires[i][1];
            dp[1]=min(dp[1], f);
            ll numLaps=2;
            ll total=f;
            ll curr=r;
            while(numLaps<=laps and f*curr<=f+cT)
            {
                total+=(f*curr);
                dp[numLaps]=min(dp[numLaps],total);
                curr*=r;
                numLaps++;
            }
        }
        
        //2)Now fill the dp array given the transition : dp[i] = min(dp[i] ,  dp[j]+dp[i-j]+cT) i.e. break the laps into laps of size j and i-j
        for(int i=2; i<=laps; i++)
        {
            for(int j=1; j<i; j++)
                dp[i]=min(dp[i], dp[j]+dp[i-j]+cT);
        }
        
        return dp[laps];
    }
};