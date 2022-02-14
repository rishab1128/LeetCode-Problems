class Solution {
public:
    long long minimumRemoval(vector<int>& arr) 
    {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        vector<long long>pref(n) , suff(n);
        pref[0]=arr[0] , suff[n-1]=arr[n-1];
        for(int i=1; i<n; i++)
            pref[i]=pref[i-1]+arr[i];
        for(int i=n-2; i>=0; i--)
            suff[i]=suff[i+1]+arr[i];
        
        long long ans=LLONG_MAX;
        for(int i=0; i<n; i++)
        {
            long long rightSum = i+1<n ? (suff[i+1]-(n-1-i)*(long long)arr[i]) : 0;
            long long leftSum = i-1>=0 ? pref[i-1] : 0;
            ans=min(ans,leftSum+rightSum);
        }
        return ans;
        
    }
};