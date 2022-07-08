class Solution {
public:
    vector<int>dp;
    int calc(int i)
    {
        if(i==1)
            return 0;
        
        if(i<dp.size() and dp[i]!=-1)
            return dp[i];
        
        int ans = 0;
        if(i%2)
            ans = 1+calc(3*i+1);
        else
            ans = 1+calc(i/2);
        
        if(i<dp.size())
            dp[i] = ans;
        return ans;
    }
    
    int getKth(int lo, int hi, int k) 
    {
        dp.resize(1001,-1);
        vector<pair<int,int>>ans;
        for(int i=lo; i<=hi; i++)
            ans.push_back(make_pair(calc(i),i));
            
        // for(auto x: ans)
        //     cout<<x<<" ";
        // cout<<endl;
        
        sort(ans.begin(),ans.end());
        return ans[k-1].second;
    }
};