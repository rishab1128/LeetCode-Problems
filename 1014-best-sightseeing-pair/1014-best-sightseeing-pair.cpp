class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& arr) 
    {
        //dp[0] = 0;
        //dp[i] = dp[i-1]-arr[i-1]+arr[i]-1 ;
        //Ans  = *max_element of dp array
        //dp[j] := maxSum/(finds appropriate i) if that element is chosen as my arr[j] 
        
        //Credit : @fcukcode
        
        int n = arr.size();
        vector<int>dp(n,0);
        dp[0]= 0 ;
        for(int i=1; i<n; i++)
        {
            dp[i] = max( dp[i-1]-arr[i-1]+arr[i]-1 , arr[i]+arr[i-1]-1);
        }
        return *max_element(dp.begin(),dp.end());
        
    }
};