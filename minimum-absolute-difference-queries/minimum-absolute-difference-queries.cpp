class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& que) 
    {
        int n=nums.size();
        int pref[n][101];
        vector<int>cnt(101,0);
        for(int i=0; i<n; i++)
        {
            cnt[nums[i]]++;
            for(int j=0; j<101; j++)
                pref[i][j]=cnt[j];
        }
        int q=que.size();
        vector<int>ans(q,-1);
        for(int i=0; i<q; i++)
        {
            int l=que[i][0] , r=que[i][1];
            vector<int>cnt(101,0);
            if(l-1>=0)
            {
                for(int j=0; j<101; j++)
                {
                    cnt[j]=pref[l-1][j]-pref[r][j];
                }
                int prev=0 , mini=INT_MAX;
                for(int j=1; j<101; j++)
                {
                    if(cnt[j]==0)
                        continue;
                    if(prev!=0)
                        mini=min(mini,j-prev);
                    prev=j;
                }
                if(mini!=INT_MAX)
                    ans[i]=mini;
            }
            else
            {
                for(int j=0; j<101; j++)
                {
                    cnt[j]=pref[r][j];
                }
                int prev=0 , mini=INT_MAX;
                for(int j=1; j<101; j++)
                {
                    if(cnt[j]==0)
                        continue;
                    if(prev!=0)
                        mini=min(mini,j-prev);
                    prev=j;
                }
                if(mini!=INT_MAX)
                    ans[i]=mini;
            }
        }
        return ans;
        
    }
};