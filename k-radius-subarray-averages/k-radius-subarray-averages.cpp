class Solution {
public:
    vector<int> getAverages(vector<int>& arr, int k) 
    {
        int n=arr.size();
        vector<long long>pref(n,0);
        pref[0]=arr[0];
        for(int i=1; i<n; i++)
            pref[i]=pref[i-1]+arr[i];
        
        vector<int>ans(n,-1);
        for(int i=k; i<n-k; i++)
        {
            int left=i-k , right=i+k;
            long long res=left-1>=0 ? pref[right]-pref[left-1] : pref[right];
            res/=(2*k+1);
            ans[i]=(int)res;
        }
        return ans;
        
    }
};