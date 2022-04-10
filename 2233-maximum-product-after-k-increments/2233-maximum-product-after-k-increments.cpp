using ll=long long;
const ll mod = 1e9+7;
class Solution {
public:
    int maximumProduct(vector<int>& arr, int k) 
    {
        priority_queue<ll,vector<ll>,greater<>>pq;
        for(auto x: arr)
            pq.push(x);
        
        while(k>0)
        {
            ll top = pq.top();
            top++;
            pq.pop();
            pq.push(top);
            // cout<<pq.top()<<endl;
            k--;
        }
        
        ll ans=1;
        while(!pq.empty()){
            ans*=pq.top();
            pq.pop();
            ans%=mod;
        }
        
        return ans;
        
        
    }
};