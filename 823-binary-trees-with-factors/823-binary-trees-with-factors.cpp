using ll=long long;
const ll mod=pow(10,9)+7;
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) 
    {
        sort(arr.begin(),arr.end());
        unordered_map<ll , ll>dp;
        ll ans=0;
        for(auto x: arr)
            dp[x]=1;
        for(int i=0; i<arr.size(); i++)
        {
            int x=arr[i];
            for(int j=0; j<i; j++)
            {
                int y=arr[j] , z=arr[i]/arr[j];
                if(y*z==x)
                    dp[x]=(dp[x]%mod+(dp[y]%mod*dp[z]%mod))%mod;
            }
            ans+=dp[x]%mod;
        }
        return ans%mod;
        
    }
};