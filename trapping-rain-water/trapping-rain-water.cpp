class Solution {
public:
    //Using prefix and suffix array
    int trap(vector<int>& arr) 
    {
        int n=arr.size();
        vector<int>pref(n),suff(n);
        
        pref[0]=arr[0];
        for(int i=1; i<n; i++)
            pref[i]=max(pref[i-1],arr[i]);
        
        suff[n-1]=arr[n-1];
        for(int i=n-2; i>=0; i--)
            suff[i]=max(suff[i+1],arr[i]);
        
        int ans=0;
        for(int i=1; i<n-1; i++)
        {
            int water_stored=min(pref[i],suff[i])-arr[i];
            ans+=water_stored;
        }
        return ans;
        
        
    }
};