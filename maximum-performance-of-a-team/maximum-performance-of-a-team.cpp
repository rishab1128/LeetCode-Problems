using ll=long;
const ll mod=1e9+7;

bool cmp(const pair<ll,ll>&a, const pair<ll,ll>&b)
{
    return a.first>b.first;
}

class Solution {
public:
    
    int maxPerformance(int n, vector<int>& speed, vector<int>& effi, int k) 
    {
        vector<pair<int,int>>arr(n);
        for(int i=0; i<n; i++)
        {
            arr[i].first=effi[i];
            arr[i].second=speed[i];
        }
        
        sort(arr.begin(),arr.end(),cmp);
        
        // for(auto x: arr)
        //     cout<<x.first<<" "<<x.second<<endl;
        
        priority_queue <int, vector<int>, greater<int> > pq; //min-heap
        
        ll sum=0 , ans=0;
        for(ll i=0; i<k; i++)
        {
            sum+=arr[i].second;
            pq.push(arr[i].second);
            ll tmp=(sum*arr[i].first);
            ans=max(ans,tmp);
            //sum%=mod;
        }
        
        //cout<<ans<<endl;
        
        for(int i=k; i<n; i++)
        {
            sum-=pq.top();
            pq.pop();
            sum+=arr[i].second;
            pq.push(arr[i].second);
            ll tmp=(sum*arr[i].first);
            ans=max(ans,tmp);
        }
        
        
        return ans%mod;
        
    }
};