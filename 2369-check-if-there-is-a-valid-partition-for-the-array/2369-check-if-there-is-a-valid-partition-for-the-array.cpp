class Solution {
public:
    
    vector<int>dp;
    
    int recur(vector<int>&arr, int i)
    {
        if(i==arr.size())
            return 1;
        
        
        if(dp[i]!=-1)
            return dp[i];
        
        //Check for subarray of sz 3
        if(i+2<arr.size())
        {
            if(arr[i]==arr[i+1] and arr[i+1]==arr[i+2] and recur(arr,i+3))
                return dp[i] = 1;
            
            if(arr[i]==arr[i+1] and recur(arr,i+2))
                return dp[i] = 1;
            
            else if(arr[i+1]-arr[i]==1 and arr[i+2]-arr[i+1]==1 and recur(arr,i+3))
                return dp[i] = 1;
            
            return dp[i] = 0;
        }
        
        if(i+1<arr.size() and arr[i]==arr[i+1] and recur(arr,i+2))
                return dp[i] = 1;
        
        return dp[i] = 0;
    }
    
    bool validPartition(vector<int>& arr) 
    {
        int n = arr.size();
        dp.resize(n+1,-1);
        return recur(arr,0);
    }
};