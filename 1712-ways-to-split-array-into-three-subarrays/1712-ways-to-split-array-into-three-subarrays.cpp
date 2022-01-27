using ll=long long;
const ll mod=1e9+7;

class Solution {
public:
    int waysToSplit(vector<int>& arr) 
    {
        int n=arr.size();
        ll ans=0;
        
        vector<ll>pref(n),suff(n);
        
        pref[0]=arr[0];
        for(int i=1; i<n; i++)
            pref[i]=pref[i-1]+arr[i];
        
        suff[n-1]=arr[n-1];
        for(int i=n-2; i>=0; i--)
            suff[i]=suff[i+1]+arr[i];
        
        
        for(int i=0; i<n; i++)
        {
            ll left=pref[i];
            int pos1=lower_bound(pref.begin()+i+1, pref.end(),2*left)-pref.begin();
            // cout<<"pos1 = "<<pos1<<" and LEFT = "<<left<<endl;
            if(pos1+1<n and pref[pos1]-left<=suff[pos1+1])
            {
                int low=pos1+1 , high=n-1 , pos2=pos1;
                while(low<=high)
                {
                    int mid=low+(high-low)/2;
                    if(mid+1<n and pref[mid]-left<=suff[mid+1])
                    {
                        pos2=mid;
                        low=mid+1;
                    }
                    else
                        high=mid-1;
                }
                ans+=(pos2-pos1+1);
                ans%=mod;
                // cout<<"pos2 = "<<pos2<<" and ANS = "<<ans<<endl<<endl;
            }
        }
        
        return ans;
        
        
    }
};