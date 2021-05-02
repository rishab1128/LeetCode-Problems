class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& inter, vector<int>& que) 
    {
        int n=inter.size();
        vector<int>tmp=que;
        sort(inter.begin() , inter.end());
        sort(que.begin() , que.end());
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int>mp;
        vector<int>ans;
        int j=0;
        for(int i=0; i<(int)que.size() ; i++)
        {
            while(j<n and inter[j][0]<=que[i])
            {
                int r=inter[j][1] , l=inter[j][0];
                pq.push({-1*(r-l+1),r});
                j++;
            }
            while(pq.size()> 0 and pq.top().second<que[i])
                pq.pop();
            if(pq.size()>0)
                mp[que[i]]=-1*(pq.top().first);
            else
                mp[que[i]]=-1;
        }
        for(int q: tmp)
        {
            ans.push_back(mp[q]);
        }
        return ans;
        
    }
};