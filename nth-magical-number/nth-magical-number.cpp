using ll=long long;
class Solution {
public:
    const int mod=1e9+7;
    
    int lcm(int a , int b)
    {
        ll prod=(ll)a*(ll)b;
        return prod/__gcd(a,b);
    }
    
    bool check(long long mid , int n , int a , int b)
    {
        //cout<<mid<<" ";
        ll sol=mid/a + mid/b - mid/lcm(a,b);
        //cout<<sol<<endl;
        return sol>=n;
    }
    
    int nthMagicalNumber(int n, int a, int b) 
    {
        ll low=1,high=(ll)max(a,b)*(ll)n;
        //cout<<high<<endl;
        ll ans=1;
        while(low<=high)
        {
            ll mid=low+(high-low)/2;
            //cout<<mid<<" ";
            if(check(mid,n,a,b))
            {
                ans=mid%mod;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return (int)ans;
    }
};