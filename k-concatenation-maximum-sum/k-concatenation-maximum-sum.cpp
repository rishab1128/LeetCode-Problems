#include<bits/stdc++.h>
using ll=long long;
using namespace std;
const ll mod=1e9+7;

class Solution {
public:
    ll kadane(vector<int>&arr , int n)
    {
        long long best=0,curr=0;
        for(int i=0; i<n; i++)
        {
            if(curr<0)
                curr=0;
            curr+=arr[i];
            //curr=curr%mod;
            best=max(best,curr);
        }
        return best;
    }
    
    int kConcatenationMaxSum(vector<int>& arr, int k) 
    {
        int n=arr.size();
        ll best1=kadane(arr,n);
        if(k==1)
            return best1;
        ll sum=accumulate(arr.begin(),arr.end(),0);
        ll best2=(sum*k)%mod;
        ll best3=0;
        ll curr=0 ,best_pref_sum=0 , best_suff_sum=0;
        for(int i=0; i<n; i++)
        {
            curr+=arr[i];
            best_pref_sum=max(best_pref_sum , curr);
        }
        curr=0;
        for(int i=n-1; i>=0; i--)
        {
            curr+=arr[i];
            best_suff_sum=max(best_suff_sum , curr);
        }
        cout<<best_pref_sum<<" "<<best_suff_sum<<endl;
        if(k-2>0)
            best3=best_suff_sum+(sum*(k-2))%mod+best_pref_sum;
        else if(k==2)
            best3=best_suff_sum+best_pref_sum;
        ll best4=best_suff_sum+best_pref_sum;
        cout<<best1<<" "<<best2<<" "<<best3<<" "<<best4<<endl;
        return max({best1 , best2 , best3 , best4}) % mod;
    }
};