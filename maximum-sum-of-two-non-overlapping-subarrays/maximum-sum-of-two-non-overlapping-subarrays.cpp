class Solution {
public:
    int n;
    int func(vector<int>&pref , int s1, int e1, int n2)
    {
        int s2=0 , maxi=0;
        for(int e2=n2; e2<=n; e2++)
        {
            if(e2<=s1 || e1<=s2)
            {
                int sum=pref[e2]-pref[s2];
                maxi=max(maxi,sum);
            }
            s2++;
        }
        return maxi;
    }
    
    int maxSumTwoNoOverlap(vector<int>& arr, int n1, int n2)
    {
        n=arr.size();
        if(n1+n2==n)
        {
            int sum=accumulate(arr.begin(),arr.end(),0);
            return sum;
        }
        
        vector<int>pref(n+1);
        pref[0]=0;
        for(int i=1; i<=n; i++)
            pref[i]=pref[i-1]+arr[i-1];
        
        int s1=0 , ans=0;
        for(int e1=n1; e1<=n; e1++)
        {
            int sum1=pref[e1]-pref[s1];
            int sum2=func(pref,s1,e1,n2);
            ans=max(ans,sum1+sum2);
            s1++;
        }
        return ans;
    }
};