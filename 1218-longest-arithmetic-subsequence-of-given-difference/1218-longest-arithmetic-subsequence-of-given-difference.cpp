class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) 
    {
        int n = arr.size();
        unordered_map<int,int>mp;
        mp[arr[0]]=0;
        vector<int>dp(n,1);
        for(int i=1; i<n; i++)
        {
            int prev = arr[i]-diff;
            if(!mp.count(prev))
                dp[i]=1;
            else
                dp[i]=dp[mp[prev]]+1;
            mp[arr[i]]=i;
        }
        // for(auto x: dp)
        //     cout<<x<<" ";
        // cout<<endl;
        
        return *max_element(dp.begin(),dp.end());
        
    }
};