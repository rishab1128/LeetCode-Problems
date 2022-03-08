using ll=long long;
class Solution {
public:
    ll minimalKSum(vector<int>& Arr, int K) 
    {
        
        vector<ll>arr;
        for(auto x: Arr)
            arr.push_back(x);
        
        ll k=K;
        
        sort(arr.begin(),arr.end());
        arr.erase( unique( arr.begin(), arr.end() ), arr.end() );
        int n = arr.size();
        
        // for(auto x: arr)
        //     cout<<x<<" ";
        // cout<<endl;
        
        ll ans=0;
        if(arr[0]!=1)
        {
            if(k<arr[0]){
                ans=k*(k+1)/2;
                return ans;
            }
                
            ll t=arr[0]-1;
            ans+=t*(t+1)/2;
            k-=t;
        }
        
        for(int i=0; i<n-1; i++){
            if(k>0 and arr[i]+k>=arr[i+1])
            {
                int m=arr[i+1]-arr[i]-1;
                k-=m;
                ll a=arr[i]+1;
                ll sum=m*(2*a+m-1)/2;
                ans+=sum;
                // cout<<arr[i]<<" "<<arr[i+1]<<" "<<m<<" "<<ans<<" "<<k<<endl;
            }
            else if(k>0 and arr[i]+k<arr[i+1])
            {
                int m=k;
                ll a=arr[i]+1;
                ll sum=m*(2*a+m-1)/2;
                ans+=sum;
                // cout<<arr[i]<<" "<<arr[i+1]<<" "<<m<<" "<<ans<<" "<<k<<endl;
                k=0;
            }
            if(k==0)
                break;
        }
        
        // cout<<ans<<" "<<k<<endl;
        
        if(k>0){
            int m=k;
            ll a=arr[n-1]+1;
            ll sum=m*(2*a+m-1)/2;
            ans+=sum;
        }
        
        return ans;
        
        
    }
};