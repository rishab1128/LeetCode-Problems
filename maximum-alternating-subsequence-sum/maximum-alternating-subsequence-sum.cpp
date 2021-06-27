using ll=long long;
class Solution {
public:
    ll dp[100001][2];
    ll func(vector<int>&arr, int i, int flag)
    {
        if(i>=arr.size())
            return 0;
        if(dp[i][flag])
            return dp[i][flag];
        ll op1=0,op2=0;
        if(flag==0)
        {
            op1=arr[i]+func(arr,i+1,1);
            op2=func(arr,i+1,0);
        }
        else
        {
            op1=-arr[i]+func(arr,i+1,0);
            op2=func(arr,i+1,1);
        }
        return dp[i][flag]=max(op1,op2);
    }
    
    ll maxAlternatingSum(vector<int>& arr) 
    {
        memset(dp,0,sizeof(dp));
        return func(arr,0,0);
    }
};