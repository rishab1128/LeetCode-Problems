class Solution {
public:
    int numSubarraysWithSum(vector<int>& arr, int goal) 
    {
        int n=arr.size();
        vector<int>pref(n);
        pref[0]=arr[0];
        for(int i=1; i<n; i++)
            pref[i]=pref[i-1]+arr[i];
        
        unordered_map<int,int>mp;
        mp[0]++;
        int ans=0;
        for(int i=0; i<n; i++)
        {
            int target=pref[i]-goal;
            ans+=mp[target];
            mp[pref[i]]++;
        }
        
        return ans;
        
    }
};