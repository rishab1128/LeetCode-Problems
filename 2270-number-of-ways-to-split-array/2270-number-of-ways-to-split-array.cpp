class Solution {
public:
    int waysToSplitArray(vector<int>& arr) 
    {
        int n = arr.size();
        vector<long long>pref(n),suff(n);
        pref[0]=arr[0];
        suff[n-1]=arr[n-1];
        for(int i=1; i<n; i++)
            pref[i]=pref[i-1]+arr[i];
        for(int i=n-2; i>=0; i--)
            suff[i]=suff[i+1]+arr[i];
        
        
        /*for(auto x: pref)
            cout<<x<<" ";
        cout<<endl;
        
        for(auto x: suff)
            cout<<x<<" ";
        cout<<endl;*/
        
        int cnt = 0;
        for(int i=0; i<n-1; i++)
        {
            if(pref[i]>=suff[i+1])
                cnt++;
        }
        
        return cnt;
        
    }
};