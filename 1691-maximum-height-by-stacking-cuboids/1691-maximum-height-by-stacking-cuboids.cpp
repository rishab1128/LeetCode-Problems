class Solution {
public:
    int maxHeight(vector<vector<int>>& arr) 
    {
        for(auto &brr : arr)
            sort(brr.begin() , brr.end());
        
        sort(arr.begin(),arr.end());
        
        int n = arr.size();
        vector<int>dp(n,0);
        dp[0]=arr[0][2];
        for(int i=1; i<n; i++)
        {
            dp[i]=arr[i][2];
            for(int j=i-1; j>=0; j--)
            {
                if(arr[j][0]<=arr[i][0] and arr[j][1]<=arr[i][1] and arr[j][2]<=arr[i][2])
                    dp[i]=max(dp[i],dp[j]+arr[i][2]);
            }
        }
        int ans = *max_element(dp.begin(),dp.end());
        return ans;
        
    }
};