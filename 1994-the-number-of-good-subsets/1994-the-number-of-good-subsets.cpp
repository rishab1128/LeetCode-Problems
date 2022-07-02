using ll = long long;
const int mod = 1e9+7;
class Solution {
public:
    
    unordered_map<ll,ll>freq;
    
    ll recur(vector<ll>&brr, ll idx, ll mask)
    {
        if(idx==brr.size())
            return (mask>0);
        
        if(brr[idx]&mask)
            return recur(brr,idx+1,mask) % mod;
        
        ll op1 = (freq[brr[idx]] % mod * recur(brr,idx+1,mask|brr[idx]) % mod) % mod;
        ll op2 = recur(brr,idx+1,mask) % mod;
        return (op1 % mod + op2 % mod) % mod;
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
            
            if(arr[i]%4==0 || arr[i]%9==0 || arr[i]%25==0)
                continue;
            
            ll num = 0 , flag=1;
            for(int j=0; j<primes.size(); j++)
            {
                ll ct = 0;
                while(arr[i]%primes[j]==0)
                {
                    arr[i]/=primes[j];
                    ct++;
                    if(ct>1)
                        break;
                }
                if(ct>1)
                {
                    flag=0;
                    break;
                }
                else if(ct==1)
                    num+=(1<<j);
            }
            
            if(!flag)
                continue;
            
            if(num==0)
            {
                ones++;
                continue;
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
        }
        
        sort(tmp.begin(),tmp.end());
        for(auto x: tmp)
            cout<<x<<" ";
        cout<<endl;*/
        
        ll ans = recur(brr,0,0) % mod;
        
        while(ones--)
            ans = ( (ll)ans*2LL)%mod;
        
        return ans;
        
    }
};