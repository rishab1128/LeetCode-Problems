class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& arr, vector<int>& per) 
    {
        int n  = arr.size();
        vector<int>start(n) , endo(n);
        for(int i=0; i<n; i++)
        {
            start[i]=arr[i][0];
            endo[i]=arr[i][1];
        }
        sort(start.begin(),start.end());
        sort(endo.begin(),endo.end());
        
        int m = per.size();
        vector<int>ans(m);
        for(int i=0; i<m; i++)
        {
            int t = per[i];
            int started_blooming = upper_bound(start.begin(),start.end(),t)-start.begin();
            int already_ended_blooming = lower_bound(endo.begin(),endo.end(),t)-endo.begin();
            ans[i] = started_blooming - already_ended_blooming;
        }
        
        return ans;
        
    }
};