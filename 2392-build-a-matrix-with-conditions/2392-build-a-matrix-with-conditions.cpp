class Solution {
public:
    
    bool topoSort(int k, vector<vector<int>>&adj, vector<int>&indeg, vector<int>&res)
    {
        queue<int>q;
        for(int i=1; i<=k; i++)
        {
            if(!indeg[i])
                q.push(i);
        }
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            res.push_back(node);
            for(auto child : adj[node])
            {
                indeg[child]--;
                if(!indeg[child])
                    q.push(child);
            }
        }
        return res.size()==k;
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& arr1, vector<vector<int>>& arr2) 
    {
        vector<vector<int>>adj1(k+1) , adj2(k+1);
        vector<int>indeg1(k+1,0) , indeg2(k+1,0);
        
        for(auto edge : arr1)
        {
            int u = edge[0] , v = edge[1];
            adj1[u].push_back(v);
            indeg1[v]++;
        }
        
        for(auto edge : arr2)
        {
            int u = edge[0] , v = edge[1];
            adj2[u].push_back(v);
            indeg2[v]++;
        }
        
        vector<int>rowOrder , colOrder;
        
        bool check1  = topoSort(k,adj1,indeg1,rowOrder);
        bool check2  = topoSort(k,adj2,indeg2,colOrder);
        
        if(!check1 || !check2)
            return {};
        
        vector<vector<int>>ans(k,vector<int>(k,0));
        
        unordered_map<int,int>mp;
        for(int i=0; i<k; i++)
            mp[colOrder[i]] = i;
        
        for(int rowIdx=0; rowIdx<k; rowIdx++)
        {
            int colIdx = mp[rowOrder[rowIdx]];
            ans[rowIdx][colIdx] = rowOrder[rowIdx];
        }
        
        return ans;
        
    }
};