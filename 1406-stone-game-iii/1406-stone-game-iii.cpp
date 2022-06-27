class Solution {
public:
    
    vector<int>dp;
    int n;
    const int INF = -0x3f3f3f3f;
    
    //This recursive function mainly calculates the maximum profit that alice can make
    int recurse(vector<int> &arr, int idx)
    {
        if(idx>=n)
            return 0;
        
        if(dp[idx]!=INF)
            return dp[idx];
        
        
        int op1 = INT_MIN , op2 = INT_MIN , op3 = INT_MIN;
        
        op1 = arr[idx] - recurse(arr,idx+1);
        
        if(idx+1<n)
            op2 = arr[idx]+arr[idx+1]-recurse(arr,idx+2);
        
        if(idx+2<n)
            op3 = arr[idx]+arr[idx+1]+arr[idx+2]-recurse(arr,idx+3);
        
        return dp[idx] = max({op1,op2,op3});
    }

    string stoneGameIII(vector<int>& arr) 
    {
        n  = arr.size();
        dp.resize(n+1,INF);
        int profit = recurse(arr,0);
        // cout<<profit<<endl;
        if(profit>0)
            return "Alice";
        else if(profit==0)
            return "Tie";
        return "Bob";
    }
};