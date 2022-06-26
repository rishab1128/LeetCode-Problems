class Solution {
public:
    int dp[101][101]= {};
    
    int recurse(vector<int> &v, int idx, int m, int n)
    {
        if(idx>=n)
            return 0;
        
        int sum = 0; 
        if(idx+2*m>=v.size())
        {
            for(int i=idx;i<n;i++){
                sum+=v[i];     
            }
            return sum;
        }
        
        if(dp[idx][m] != 0)
            return dp[idx][m];
        
        
        int aliceProfit = -INT_MAX;
        sum = 0;
        int cnt = 0;
        for(int i = idx; i<min(2*m+idx, n); i++){
            cnt++;
            sum+=v[i];
            aliceProfit = max(aliceProfit, sum - recurse(v, i+1, max(cnt, m), n));
        }
        dp[idx][m] = aliceProfit;
        return aliceProfit;
    }
    
    
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        int totalSum = accumulate(piles.begin(), piles.end(), 0);
        
        int aliceProfit = recurse(piles , 0, 1,n);
        
        int aliceScore  = (totalSum + aliceProfit)/2;
        return aliceScore;
    }
};