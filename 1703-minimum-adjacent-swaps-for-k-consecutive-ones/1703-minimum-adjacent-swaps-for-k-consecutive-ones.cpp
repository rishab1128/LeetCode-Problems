class Solution {
public:
    int minMoves(vector<int>& arr, int k) 
    {
        int n=arr.size();
        vector<int>idx;
        idx.push_back(0);
        for(int i=0; i<n; i++)
        {
            if(arr[i])
                idx.push_back(i);
        }
        
        int m=idx.size();
        vector<long long>pref(m,0);
        for(int i=1; i<m; i++)
            pref[i]=pref[i-1]+idx[i];
        
        long long ans=LLONG_MAX;
        for(int l=1,r=k; r<m ; l++ , r++)
        {
            int mid=(l+r)/2;
            int curr=idx[mid];
            
            int radius = k%2 ? (k-1)/2 : (k-2)/2;
            long long right = pref[r]-pref[mid];
            long long left =  pref[mid-1]-pref[l-1];
            
            int extra = (radius+1)*radius;
            
            if(k%2==0)
                extra+=curr+(radius+1);
            
            ans=min(ans , (long long)right-left-extra);
        }
        
        return ans;
        
        
    }
};