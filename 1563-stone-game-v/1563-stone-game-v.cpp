class Solution {
public:
    
    int n;
    vector<int>pref;
    int dp[501][501];
    
    int recur(vector<int>&arr, int left , int right)
    {
        if(left>right)
            return 0;
        
        if(dp[left][right]!=-1)
            return dp[left][right];
        
        int ans = 0;
        
        for(int i=left; i<=right-1; i++)
        {
            int leftSum = left-1>=0 ? pref[i]-pref[left-1] : pref[i];
            int rightSum = pref[right]-pref[i];
            
            if(leftSum>rightSum)
                ans = max(ans , rightSum + recur(arr,i+1,right));
            
            else if(leftSum<rightSum)
                ans = max(ans , leftSum + recur(arr,left,i));
            
            else
                ans = max({ans, rightSum + recur(arr,i+1,right) , leftSum + recur(arr,left,i)});
            
            // cout<<i<<" "<<leftSum<<" "<<rightSum<<" "<<ans<<endl;
        }
        
        return dp[left][right] = ans;
    }
    
    int stoneGameV(vector<int>& arr) 
    {
        n = arr.size();
        pref.resize(n,0);
        pref[0]=arr[0];
        for(int i=1; i<n; i++)
            pref[i]=pref[i-1]+arr[i];
        
        memset(dp,-1,sizeof(dp));
        
        int ans = recur(arr,0,n-1);
        return ans;
    }
};