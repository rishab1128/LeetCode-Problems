const int INF=INT_MAX;
class Solution {
public:
    string largestNumber(vector<int>& cost, int target) 
    {
        int n = cost.size();
        vector<int> dp(target+1,-INF);
        //dp[i] := The most digits we can use to reach exactly value i
        dp[0] = 0;
        for(int i=1; i<=target; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(cost[j]<=i)
                    dp[i] = max(dp[i],1+dp[i-cost[j]]);
            }
        }
        
        // cout<<dp[target]<<endl;
        
        if(dp[target]<0)
            return "0";
        
        
        
        string ans= "";
        for(int i=8; i>=0; i--)
        {
            while(target>=cost[i] and dp[target]==1+dp[target-cost[i]]){
                ans+=to_string(i+1);
                target-=cost[i];
            }
                
        }
        return ans;
        
    }
};