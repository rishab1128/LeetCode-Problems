class Solution {
public:
    static bool cmp(const vector<int>&a , const vector<int>&b)
    {
        return a[1]<b[1];
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        int n = startTime.size();
        vector<vector<int>>arr(n);
        vector<int>endi(n);
        vector<int>dp(n);
        
        for(int i=0; i<n; i++)
            arr[i]={startTime[i],endTime[i],profit[i]};
        
        sort(arr.begin(),arr.end(),cmp);
        
        for(int i=0; i<n; i++)
            endi[i]=arr[i][1];
        
        dp[0]=arr[0][2];
        for(int i=1; i<n; i++)
        {
            int pos = upper_bound(endi.begin(),endi.end(),arr[i][0])-endi.begin();
            pos--;
            if(pos>=0)
                dp[i]=max(arr[i][2]+dp[pos],dp[i-1]);
            else
                dp[i]=max(arr[i][2],dp[i-1]);
        }
        int ans = dp[n-1];
        return ans;
    }
};