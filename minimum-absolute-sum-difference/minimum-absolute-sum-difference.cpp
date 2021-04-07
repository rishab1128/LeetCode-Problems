#include<bits/stdc++.h>
using namespace std;

typedef string                         STR;
typedef long long                      ll;
typedef long double                    ld;
typedef unsigned long long             ull;
typedef vector<int>                    vi;
typedef priority_queue<int>            pqi;
typedef vector<ll>                     vll;
typedef vector<ull>                    vull;
typedef vector<STR>                    vs;
typedef vector<char>                   vc;
typedef pair<int, int>                 pii;
typedef pair<ll, ll>                   pll;
typedef pair<STR, int>                 psi;
typedef pair<char, ll>                 pcl;
typedef pair<int, STR>                 pis;
typedef vector<pii>                    vpii;
typedef vector<pll>                    vpll;
typedef vector<pcl>                    vpcl;
typedef map<int, int>                  mii;
typedef map<ll, ll>                    mll;
typedef map<STR, int>                  msi;
typedef map<char, int>                 mci;
typedef map<int, STR>                  mis;
typedef set<STR>                       ss;
typedef set<char>                      sc;
typedef set<int>                       si;
typedef set<ll>                        sll;

#define FF                             first
#define SS                             second
#define pb                             push_back
#define pf                             push_front
#define mp                             make_pair
#define all(a)                         (a).begin(), (a).end()
#define ps(x,y)                        fixed<<setprecision(y)<<x
#define setbits(x)                     __builtin_popcountll(x)
#define zrobits(x)                     __builtin_ctzll(x)
#define d2b(x,n)                       bitset<x>(n).to_string()
#define b2d(x,n)                       bitset<x>(n).to_ulong()
#define f(i,a,n)                       for(ll i=a; i<n; i++)
#define f1(i,b,m)                      for(ll i=b; i<=m; i++)
#define f2(i,x,y)                      for(ll i=x; i>=y; i--)
#define fsort(a)                       sort(a.begin(), a.end())
#define rsort(a)                       sort(a.rbegin(), a.rend())
#define w(t)                           ll t; cin>>t; while(t--)
#define UB                             upper_bound
#define LB                             lower_bound
#define BS                             binary_search
#define EB                             emplace_back
#define Max(x,y,z)                     max(x,max(y,z))
#define Min(x,y,z)                     min(x,min(y,z))
#define Ans(a,b) 					   cout<<"Case #"<<a<<": "<<b<<"\n";

const ll mod     = 1000000007;
const ll SIZE    = 1000001;
const int INF    = 0x3f3f3f3f;
const ll ll_INF  = 0x3f3f3f3f3f3f3f3f;
const ld PI      = acos(-1);
const ll MAXN    = numeric_limits<ll>::max();
const ll MAX     = 90000000;


class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) 
    {
    	mll mp;
    	ll n=nums1.size() , s=0;
    	f(i,0,n)
    	{
    		s=(s%mod+abs(nums1[i]-nums2[i])%mod)%mod;
    		mp[i]=abs(nums1[i]-nums2[i]);
    	}
    	vll arr(n);
    	f(i,0,n)arr[i]=nums1[i];
    	fsort(arr);
    	ll ans=s;
    	f(i,0,n)
    	{
    		ll pos=UB(all(arr),nums2[i])-arr.begin();
    		ll tmp=s;
    		if(pos>0 && pos<n)
    		{
    			ll mini=min(abs(arr[pos]-nums2[i]),abs(arr[pos-1]-nums2[i]));
    			tmp=((tmp-mp[i])%mod+mini%mod);
    			ans=min({ans,tmp,s});
    		}
    		else if(pos==n)
    		{
    			tmp=((tmp-mp[i])%mod+abs(arr[pos-1]-nums2[i])%mod)%mod;
    			ans=min({ans,tmp,s});
    		}
    		else if(pos==0)
    		{
    			tmp=((tmp-mp[i])%mod+abs(arr[pos]-nums2[i])%mod)%mod;
    			ans=min({ans,tmp,s});
    		}
    	}
        
    	return ans;
        
    }
};