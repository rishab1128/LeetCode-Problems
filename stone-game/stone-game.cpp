class Solution {
public:
    int n;
    int dp[501][501];
    int func(vector<int>&piles , int i , int j , int fl)
    {
        if(i>j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int alex=0;
        if(fl==0)
            alex=max(piles[i]+func(piles,i+1,j,1) , piles[j]+func(piles,i,j-1,1));
        else
            alex=min(-piles[i]+func(piles,i+1,j,0) , -piles[j]+func(piles,i,j-1,0));
        return dp[i][j]=alex;
    }
    bool stoneGame(vector<int>& piles) 
    {
        memset(dp,-1,sizeof(dp));
        n=piles.size();
        int diff=func(piles,0,n-1,0);
        cout<<diff<<endl;
        return diff>0;
        
    }
};