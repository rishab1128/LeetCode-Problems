class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) 
    {
        int n = candies.size();
        
        unordered_map<int,vector<pair<int,char>>> adj;
        vector<int>outOftheBox(n,0);
        
        for(int i=0; i<n; i++)
        {
            for(auto boxes : containedBoxes[i])
                adj[i].push_back({boxes,'P'});
            
            for(auto boxes : keys[i])
                adj[i].push_back({boxes,'K'});
        }
        
        for(auto boxes : initialBoxes)
            outOftheBox[boxes]=1;
        
        queue<int>q;
        vector<bool>vis(n,0);
        
        for(int i=0; i<n; i++)
        {
            if(outOftheBox[i] and status[i]){
                q.push(i);
                vis[i]=1;
            }
        }
        
        long long ans = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            ans+=candies[node];
            for(auto [child,ch] : adj[node])
            {
                if(ch=='P')
                    outOftheBox[child]=1;
                else
                    status[child]=1;
                if(outOftheBox[child] and status[child] and !vis[child]){
                    q.push(child);
                    vis[child]=1;
                }
            }
        }
        
        return ans;
        
    }
};