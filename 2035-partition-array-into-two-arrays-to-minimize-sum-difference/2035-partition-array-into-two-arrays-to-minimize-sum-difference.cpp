using ll = long long;
class Solution {
public:
    int minimumDifference(vector<int>& arr) 
    {
        ll m = arr.size();
        ll n = m/2;
        
        vector<ll>leftPart , rightPart;
        
        for(ll i=0; i<n; i++)
            leftPart.push_back(arr[i]);
        
        for(ll i=n; i<2*n; i++)
            rightPart.push_back(arr[i]);
        
        map<ll,vector<ll>>ltSubSum , rtSubSum;
        
        for(ll mask=0; mask<(1<<n); mask++)
        {
            ll setBits = 0, ltSubsetSum = 0, rtSubsetSum = 0; 
            for(ll j=0; j<n; j++)
            {
                ll num = (1<<j);
                if(mask&num)
                {
                    setBits++; //num of setbits in the conf./mask = size of the subset
                    ltSubsetSum+=leftPart[j];
                    rtSubsetSum+=rightPart[j];
                }
            }
            ltSubSum[setBits].push_back(ltSubsetSum);
            rtSubSum[setBits].push_back(rtSubsetSum);
        }
        
        for(auto &[sz,vec]:rtSubSum)
            sort(vec.begin(),vec.end());
        
        ll tSum = accumulate(arr.begin() , arr.end(), 0l);
        ll ans = INT_MAX;
        
        for(ll sz1=0; sz1<=n; sz1++)
        {
            vector<ll>szSubset = ltSubSum[sz1];
            for(auto &a : szSubset)
            {
                ll X = tSum-2*a;
                ll sz2 = n-sz1;
                
                ll pos1 = lower_bound(rtSubSum[sz2].begin() , rtSubSum[sz2].end(), X/2)- rtSubSum[sz2].begin();
                ll pos2 = pos1-1;
                
                ll diff1 = INT_MAX , diff2 = INT_MAX;
                
                if(pos1<rtSubSum[sz2].size())
                    diff1 = abs(X/2 - rtSubSum[sz2][pos1]);
                
                if(pos2>=0)
                    diff2 = abs(X/2 - rtSubSum[sz2][pos2]);
                
                ll b = diff1<diff2 ?  rtSubSum[sz2][pos1] : rtSubSum[sz2][pos2];
                
                ll tmp = abs(tSum-2*a-2*b);
                ans = min(ans,tmp);
            }
        }
        
        return ans;
        
        
        
        
    }
};