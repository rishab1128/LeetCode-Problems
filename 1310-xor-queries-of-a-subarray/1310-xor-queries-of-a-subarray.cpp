class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& que) 
    {
        int n=arr.size();
        vector<int>pref(n);
        pref[0]=arr[0];
        for(int i=1; i<n; i++)
            pref[i]=pref[i-1]^arr[i];
        
        int m=que.size();
        vector<int>ans(m);
        for(int i=0; i<m; i++)
        {
            int left = que[i][0] , right = que[i][1];
            if(left==0)
                ans[i]=pref[right];
            else
                ans[i]=pref[left-1]^pref[right];
        }
        return ans;
        
        
    }
};