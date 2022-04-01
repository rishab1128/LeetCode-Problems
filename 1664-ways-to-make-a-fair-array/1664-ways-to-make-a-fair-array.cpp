using ll=long long;
class Solution {
public:
    int waysToMakeFair(vector<int>& arr) 
    {
        int n=arr.size();
        vector<ll>odd , even;
        vector<ll>oddSuff(n) , evenSuff(n);
        odd.push_back(0);
        even.push_back(0);
        oddSuff[n-1]=0;
        evenSuff[n-1]=0;
        if((n-1)%2)
            odd.push_back(arr[n-1]);
        else
            even.push_back(arr[n-1]);
        for(int i=n-2; i>=0; i--)
        {
            evenSuff[i] =  even.back() ;
            oddSuff[i]  =  odd.back() ;
            if(i%2)
                odd.push_back(arr[i]+odd.back());
            else
                even.push_back(arr[i]+even.back());
        }
        
        odd.clear();
        even.clear();
        
        vector<ll>oddPref(n) , evenPref(n);
        odd.push_back(0);
        even.push_back(arr[0]);
        oddPref[0]=0;
        evenPref[0]=0;
        
        for(int i=1; i<n; i++){
            evenPref[i] = even.back();
            oddPref[i]  = odd.back();
            if(i%2)
                odd.push_back(arr[i]+odd.back());
            else
                even.push_back(arr[i]+even.back());
        }
        
        ll ct=0;
        for(int i=0; i<n; i++){
            ll x1 = oddPref[i]+evenSuff[i] ;
            ll x2 = evenPref[i]+oddSuff[i];
            if(x1==x2)
                ct++;
        }
        
        
        
        return ct;
        
        
    }
};