class Solution {
public:
    int dp[71][5000];
    int recur(vector<vector<int>>& arr , int row , int sum , int&target)
    {
        if(row>=arr.size())
            return abs(sum-target);
        
        if(dp[row][sum]!=-1)
            return dp[row][sum];
        
        int ans=INT_MAX;
        for(int i=0; i<arr[row].size(); i++)
        {
            ans=min(ans,recur(arr,row+1,sum+arr[row][i],target));
        }
        return dp[row][sum]=ans;
    }
    
    int minimizeTheDifference(vector<vector<int>>& arr, int target) 
    {
        memset(dp,-1,sizeof(dp));
        return recur(arr,0,0,target);
    }
};