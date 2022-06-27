class Solution {
public:
    int n; 
    
    double recur(vector<int>&arr, int idx, int k, vector<vector<double>>&dp)
    {
        if(idx==n)
            return 0.0;
        
        if(dp[idx][k]!=0.0)
            return dp[idx][k];
        
        if(k==0)
        {
            int sum = 0 , len = 0;
            for(int i=idx; i<n; i++)
                sum+=arr[i] , len++;
            
            double avg = ((double)sum)/len;
            return avg;
        }
        
        int sum = 0, len = 0;
        double ans = 0.0;
        for(int i=idx; i<n; i++)
        {
            sum+=arr[i];
            len++;
            double avg = ((double)sum)/len;
            ans = max(ans , avg+recur(arr,i+1,k-1,dp));
        }
        return dp[idx][k] = ans;
    }
    
    double largestSumOfAverages(vector<int>& arr, int k) {
        n  = arr.size();
        vector<vector<double>>dp(n+1,vector<double>(k+1,0.0));
        return recur(arr,0,k-1,dp);
    }
};