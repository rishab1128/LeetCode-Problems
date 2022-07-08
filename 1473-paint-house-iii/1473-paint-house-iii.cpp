class Solution {
public:
    int m,n,target;
    int dp[101][22][101];
    int recur(vector<int>&arr, vector<vector<int>>& cost, int idx, int prevColor, int diff)
    {
        if(diff>target)
            return INT_MAX;
        
        if(idx==arr.size())
            return diff==target ? 0 : INT_MAX;
        
        if(dp[idx][prevColor][diff]!=-1)
            return dp[idx][prevColor][diff];
        
        if(arr[idx])
        {
            if(idx==0)
                return dp[idx][prevColor][diff] = recur(arr, cost, idx+1, arr[idx], diff);
            else
                return dp[idx][prevColor][diff] = recur(arr, cost, idx+1, arr[idx], arr[idx]!=prevColor ? diff+1 : diff);
        }
        
        int ans = INT_MAX;
        for(int color=1; color<=n; color++)
        {
            int tmp = recur(arr, cost, idx+1, color, (prevColor>0 and color!=prevColor) ? diff+1 : diff);
            int finalCost = (tmp!=INT_MAX) ? cost[idx][color-1]+tmp : INT_MAX;
            ans = min(ans , finalCost);
        }
        
        return dp[idx][prevColor][diff] = ans;        
    }
    
    int minCost(vector<int>&arr, vector<vector<int>>& cost, int m, int n, int target) 
    {
        memset(dp,-1,sizeof(dp));
        this->m = m;
        this->n = n;
        this->target=target-1;
        int ans = recur(arr,cost,0,0,0);
        return ans==INT_MAX ? -1 :  ans;
    }
};