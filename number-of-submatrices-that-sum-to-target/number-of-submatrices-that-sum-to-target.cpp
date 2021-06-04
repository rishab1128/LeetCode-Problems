class Solution {
public:
    int subarraySum(vector<int>& arr, int s) 
    {
        int n=arr.size();
        long long pref[n];
        pref[0]=arr[0];
        for(int i=1; i<n; i++)
            pref[i]=pref[i-1]+arr[i];
        unordered_map<long long, int>mp;
        mp[0]++;
        int ans=0;
        for(int i=0; i<n; i++)
        {
            long long target=pref[i]-s;
            if(mp.find(target)!=mp.end())
            {
                ans+=mp[target];
            }
            mp[pref[i]]++;
        }
        
        return ans;
        
    }
    
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target) 
    {
        int n=mat.size() , m=mat[0].size();
        
        int ans=0;
        for(int t=0; t<n; t++)
        {
            vector<int>arr(m,0);
            for(int i=t; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    arr[j]+=mat[i][j];
                }
                ans+=subarraySum(arr,target);
            }
        }
        
        return ans;
    }
};