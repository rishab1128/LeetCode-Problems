typedef long long       ll;
#define f(i,a,n)        for(ll i=a; i<n; i++)

class Solution {
public:
    ll LIS(vector<int>&arr, int size)
    {
        ll output[size];
        output[0]=1;
        ll ans=1;

        f(i,1,size)
        {
            output[i]=1;
            f(j,0,i)
            {
                if(arr[i]>arr[j])
                {
                    output[i]=max(output[i],output[j]+1);
                }
                else
                    continue;
            }
        }

        f(i,0,size)
        {
            ans=max(ans,output[i]);
        }

        return ans;
    }
    
    bool canBeIncreasing(vector<int>& arr) 
    {
        ll n=arr.size();
        ll len=LIS(arr,n);
        cout<<len<<endl;
        if(len>=n-1)
            return true;
        return false;
    }
};