class Solution {
public:
    unordered_map<int,int>dp;
    int calc(int i)
    {
        if(i==1)
            return 0;
        
        if(dp[i])
            return dp[i];
        
        if(i%2)
            return dp[i] = 1+calc(3*i+1);
        
        return dp[i] = 1+calc(i/2);
    }
    
    int getKth(int lo, int hi, int k) 
    {
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