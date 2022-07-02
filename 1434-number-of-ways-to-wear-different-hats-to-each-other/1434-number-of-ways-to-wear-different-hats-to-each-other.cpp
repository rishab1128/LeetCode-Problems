class Solution {
public:
    
    vector<vector<int>>arr;
    int n;
    int dp[41][1025];
    const int mod = 1e9+7;
    
    int recur(int i, int mask)
    {
        if(mask == (1<<n)-1)
            return 1;
        
        if(i>40)
            return 0;
        
        if(dp[i][mask]!=-1)
            return dp[i][mask];
        
        int op1 = recur(i+1,mask); //do not take the ith hat
        int op2 = 0;
        for(auto person : arr[i])
        {
            if(mask&(1<<person)) //person is already wearing a hat, so he cannot wear this ith hat
                continue;
            op2 = (op2 % mod + recur(i+1,mask+(1<<person)) % mod) % mod;
        }
        return dp[i][mask] = (op1 % mod + op2 % mod) % mod;
    }
    
    int numberWays(vector<vector<int>>& hats) 
    {
        arr.resize(41);
        memset(dp,-1,sizeof(dp));
        
        //arr[i] := stores all the people who can wear the ith hat
        
        n = hats.size();
        for(int i=0; i<n; i++)
        {
            for(auto hat : hats[i])
                arr[hat].push_back(i);
        }
        
        int ans = recur(0,0);
        
        return ans;
        
    }
};