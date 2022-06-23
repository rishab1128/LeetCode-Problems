class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& before) 
    {
        vector<vector<int>>adj(n);
        map<int,vector<int>>adj2;
        
        vector<int>indeg(n,0);
        map<int,int>indeg2;
        
        map<int,vector<int>>mp;
        
        int maxi = m;
        for(int i=0; i<n; i++)
        {
            if(group[i]==-1)
            {
                group[i]=maxi;
                maxi++;
            }
        }
        
        for(int i=0; i<n; i++)
        {   
            
            if(before[i].size())
            {
                for(auto node : before[i]){
                    adj[node].push_back(i);
                    int beforeNode = group[node];
                    if(beforeNode!=group[i])
                    {
                        adj2[beforeNode].push_back(group[i]);
                        indeg2[group[i]]++;
                    }
                    indeg[i]++;
                }
            }
        }
        
        queue<int>q;
        int cnt = 0;
        
        for(int i=0; i<n; i++)
        {
            if(!indeg[i]){
                q.push(i);
                cnt++;
            }
        }
        
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int node = q.front();
                q.pop();
                int grpNum = group[node];
                mp[grpNum].push_back(node);
                for(auto child : adj[node])
                {
                    indeg[child]--;
                    if(!indeg[child]){
                        q.push(child);
                        cnt++;
                    }
                }
            }
        }
        
        if(cnt!=n)
            return {};
        
        
        
        queue<int>q2;
        vector<int>order;
        
        for(int i=0; i<=maxi; i++)
        {
            if(!indeg2[i])
                q2.push(i);
        }
        
       
        while(!q2.empty())
        {
            int sz = q2.size();
            while(sz--)
            {
                int node = q2.front();
                q2.pop();
                order.push_back(node);
                for(auto child :  adj2[node])
                {
                    indeg2[child]--;
                    if(!indeg2[child])
                        q2.push(child);
                }
            }
        }
        
        
        if(order.size()!=maxi+1)
           return {}; 
        
        
        vector<int>ans;
        for(int i=0; i<order.size(); i++)
        {
            int idx = order[i];
            for(auto ele : mp[idx])
                ans.push_back(ele);
        }
        
        return ans;
    }
};