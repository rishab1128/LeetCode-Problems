class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) 
    {
        int n=arr.size() ;
        int pref[n] , suff[n];
        pref[0]=arr[0];
        for(int i=1; i<n; i++)
        {
            pref[i]=pref[i-1]*arr[i];
        }
        suff[n-1]=arr[n-1];
        for(int i=n-2; i>=0; i--)
        {
            suff[i]=suff[i+1]*arr[i];
        }
        vector<int>ans(n);
        for(int i=0; i<n; i++)
        {
            if(i==0)
                ans[i]=suff[i+1];
            else if(i==n-1)
                ans[i]=pref[i-1];
            else
                ans[i]=pref[i-1]*suff[i+1];
        }
        return ans;
    }
};