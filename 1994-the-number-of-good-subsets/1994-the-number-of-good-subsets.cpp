using ll = long long;
const int mod = 1e9+7;
class Solution {
public:
    
    //TC/SC : O(brr.size() * max Value of mask) == O(brr.size() * 1024) == O(18*1024) [ Since brr.size() can have at most 18 elements]
    
    unordered_map<ll,ll>freq;
    
    ll recur(vector<ll>&brr, ll idx, ll mask, vector<vector<ll>>&dp)
    {
        if(idx==brr.size())
            return (mask>0);
        
        if(brr[idx]&mask)
            return recur(brr,idx+1,mask,dp) % mod;
        
        if(dp[idx][mask]!=-1)
            return dp[idx][mask];
        
        ll op1 = (freq[brr[idx]] % mod * recur(brr,idx+1,mask|brr[idx],dp) % mod) % mod;
        ll op2 = recur(brr,idx+1,mask,dp) % mod;
        return dp[idx][mask] = (op1 % mod + op2 % mod) % mod;
    }
    
    int numberOfGoodSubsets(vector<int>& arr) 
    {
        ll n = arr.size();
        vector<ll>primes = {2,3,5,7,11,13,17,19,23,29};
        freq.clear();
        
        vector<ll>brr;
        ll ones = 0;
        for(int i=0; i<n; i++)
        {
            if(arr[i]==1)
            {
                ones++;
                continue;
            }
            
            if(arr[i]%4==0 || arr[i]%9==0 || arr[i]%25==0)
                continue;
            
            ll num = 0 , flag=1;
            for(int j=0; j<primes.size(); j++)
            {
                if(arr[i]%primes[j]==0)
                    num+=(1<<j);
            }
            
            freq[num]++;
            
            if(freq[num]==1)
                brr.push_back(num);
        }
        
        
        /*cout<<brr.size()<<endl;
        vector<ll>tmp;
        for(auto num: brr)
        {
            ll oriNum = 1;
            for(int i=0; i<10; i++)
            {
                if(num&(1<<i))
                    oriNum*=primes[i];
            }
            tmp.push_back(oriNum);
            cout<<num<<" ";
        }
        cout<<endl;
        
        sort(tmp.begin(),tmp.end());
        for(auto x: tmp)
            cout<<x<<" ";
        cout<<endl;*/
        
        vector<vector<ll>>dp(brr.size(),vector<ll>(1025,-1));
        
        ll ans = recur(brr,0,0,dp) % mod;
        
        while(ones--)
            ans = ( (ll)ans*2LL)%mod;
        
        return ans;
        
    }
};