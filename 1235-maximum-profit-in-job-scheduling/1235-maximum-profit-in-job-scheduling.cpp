class Solution {
public:
    vector<int>st;
    vector<int>dp;
    
    int recur(vector<vector<int>>&arr, int idx)
    {
        if(idx==arr.size())
            return 0;
        
        if(dp[idx]!=-1)
            return dp[idx];
        
        int newIdx = lower_bound(st.begin(),st.end(),arr[idx][1])-st.begin();
        
        int op1 = arr[idx][2]+recur(arr,newIdx);
        int op2 = recur(arr,idx+1);
        
        return dp[idx] = max(op1,op2);
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) 
    {
        int n = startTime.size();
        vector<vector<int>>arr(n);
        st.resize(n);
        dp.resize(n,-1);
        
        for(int i=0; i<n; i++)
            arr[i]={startTime[i],endTime[i],profit[i]};
        
        sort(arr.begin(),arr.end());
        
        for(int i=0; i<n; i++)
            st[i]=arr[i][0];
        
        int ans = recur(arr,0);
        return ans;
    }
};