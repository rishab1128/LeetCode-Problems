class Solution {
public:
    int maximumSum(vector<int>& arr) 
    {
        int n=arr.size();
        if(n==1)
            return arr[0];
        int pref[n],suff[n];
        
        pref[0]=arr[0];
        for(int i=1; i<n; i++)
        {
            pref[i]=max(pref[i-1]+arr[i],arr[i]);
        }
        
        suff[n-1]=arr[n-1];
        for(int i=n-2; i>=0; i--)
        {
            suff[i]=max(suff[i+1]+arr[i],arr[i]);
        }
        
        int ans=INT_MIN;
        for(int i=0; i<n; i++)
        {
            if(i!=0 and i!=n-1)
            {
                int s1=pref[i-1],s2=suff[i+1];
                ans=max({ans,s1,s2,s1+s2,s1+s2+arr[i]});
            }
            else if(i==0)
            {
                int s2=suff[i+1];
                ans=max({ans,s2,s2+arr[i]});
            }
            else if(i==n-1)
            {
                int s1=pref[i-1];
                ans=max({ans,s1,s1+arr[i]});
            }
        }
        
        return ans;
    }
};