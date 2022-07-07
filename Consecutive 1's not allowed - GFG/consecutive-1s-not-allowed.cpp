// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
//User function template for C++

const int mod = 1e9+7;
class Solution{
public:
	// #define ll long long
	ll n;
    ll recur(ll idx, ll curr, vector<vector<ll>>&dp)
    {
    	if(idx==n)
    		return 1;
    		
    	if(dp[idx][curr]!=-1)
    	   return dp[idx][curr];
    	
    	ll ans = 0;
    	if(curr==0)
    		ans = ( recur(idx+1,0,dp) % mod + recur(idx+1,1,dp) % mod) % mod;
    	else
    	    ans = recur(idx+1,0,dp) % mod;
    	    
        return dp[idx][curr] = ans;
    }
	ll countStrings(int N) 
	{
	    n = N;
	    vector<vector<ll>>dp(n+1,vector<ll>(2,-1));
	    ll ans = recur(0,0,dp);
	    return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends