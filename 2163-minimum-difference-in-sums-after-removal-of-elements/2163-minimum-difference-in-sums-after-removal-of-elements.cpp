//Refer  : https://leetcode.com/problems/minimum-difference-in-sums-after-removal-of-elements/discuss/1747029/Python-Explanation-with-pictures-Priority-Queue.

using ll=long long;
class Solution {
public:
    ll minimumDifference(vector<int>& arr) 
    {
        int n=arr.size()/3;
        priority_queue<ll>pq1; //keeps the smallest n prefix elements
        priority_queue<ll,vector<ll>,greater<>>pq2; //keeps the largest n suffix elements
        
        vector<ll>pref , suff;
        
        ll sum=0 , updSum;
        for(int i=0; i<n; i++)
        {
            sum+=arr[i];
            pq1.push(arr[i]);
        }
        
        pref.push_back(sum);
        for(int i=n; i<=2*n-1; i++)
        {
            ll maxi=pq1.top();
            pq1.pop();
            if(maxi>arr[i])
            {
                updSum=pref.back()-maxi+arr[i];
                pq1.push(arr[i]);
            }
            else
            {
                updSum=pref.back();
                pq1.push(maxi);
            }
            pref.push_back(updSum);
        }
        
        
        sum=0;
        for(int i=3*n-1; i>=2*n; i--)
        {
            sum+=arr[i];
            pq2.push(arr[i]);
        }
        
        suff.push_back(sum);
        for(int i=2*n-1; i>=n; i--)
        {
            ll mini=pq2.top();
            pq2.pop();
            if(mini<arr[i])
            {
                updSum=suff.back()-mini+arr[i];
                pq2.push(arr[i]);
            }
            else
            {
                updSum=suff.back();
                pq2.push(mini);
            }
            suff.push_back(updSum);
        }
        
        reverse(suff.begin(),suff.end());
        
        /*for(auto x: pref)
            cout<<x<<" ";
        cout<<endl;
        for(auto x: suff)
            cout<<x<<" ";
        cout<<endl;*/
        
        int m=pref.size();
        ll ans=LLONG_MAX;
        for(int i=0; i<m; i++)
            ans=min(ans,pref[i]-suff[i]);
        
        return ans;
        
    }
};