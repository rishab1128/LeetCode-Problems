class Solution {
public:
    int maxSumMinProduct(vector<int>& arr) 
    {
        const int mod = 1e9+7;
        int n=arr.size();
        vector<int>left(n),right(n);
        vector<long long>pref(n);
        pref[0]=arr[0];
        left[0]=-1;
        for(int i=1; i<n; i++)
        {
            int j=i-1;
            while(j!=-1 and arr[j]>=arr[i])
                j=left[j];
            left[i]=j;
            pref[i]=pref[i-1]+arr[i];
        }
        
        right[n-1]=-1;
        for(int i=n-2; i>=0; i--)
        {
            int j=i+1;
            while(j!=-1 and arr[j]>=arr[i])
                j=right[j];
            right[i]=j;
        }
        
        long long ans = 0;
        for(int i=0; i<n; i++)
        {
            int idx1=left[i] , idx2=right[i];
            long long sum = 0 , possAns = 0;
            if(i==0)
            {
                if(idx2!=-1)
                    sum = pref[idx2-1];
                else
                    sum = pref[n-1];
                
                possAns = sum*arr[i];
                ans = max(ans , possAns);
            }
            else if(i>0 and i<n-1)
            {
                if(idx1==-1 and idx2!=-1)
                    sum = pref[idx2-1];
                
                else if(idx1!=-1 and idx2==-1)
                    sum = pref[n-1] - pref[idx1];
                
                else if(idx1!=-1 and idx2!=-1)
                    sum = pref[idx2-1] - pref[idx1];
                else
                    sum = pref[n-1];
                
                possAns = sum*arr[i];
                ans = max(ans , possAns);
            }
            else
            {
                if(idx1!=-1)
                    sum = pref[n-1] - pref[idx1];
                else
                    sum = pref[n-1];
                
                possAns = sum*arr[i];
                ans = max(ans , possAns);
            }
        }
        
        ans%=mod;
        
        return ans;
    }
};