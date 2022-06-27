class Solution {
public:
    map<vector<int>,int>dp;
    int recur(vector<int>arr)
    {
        // for(auto x: arr)
        //     cout<<x<<" ";
        // cout<<endl;
        
        if(arr.size()<3)
            return 0;
        
        if(arr.size()==3)
        {
            int prod= 1;
            for(auto x: arr)
                prod*=x;
            return prod;
        }
        
        if(dp.count(arr))
            return dp[arr];
        
        
        int ans = INT_MAX;
        int n = arr.size();
        for(int k=1; k<=n-2; k++)
        {
            vector<int>v1 , v2;
            for(int i=0; i<=k; i++)
                v1.push_back(arr[i]);
            
            for(int i=k; i<=n-1; i++)
                v2.push_back(arr[i]);
            
            int prod = arr[0]*arr[k]*arr[n-1];
            ans = min(ans , prod + recur(v1) + recur(v2));
        }
        return dp[arr] = ans;
    }
    
    int minScoreTriangulation(vector<int>& arr) 
    {
        dp.clear();
        return recur(arr);
    }
};