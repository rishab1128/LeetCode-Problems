class Solution {
public:
    int dfs(int x, vector<vector<int>> &adj, vector<bool> &ha, vector<bool> &vis){
        vis[x] = true;
        if(x!=0 && adj[x].size() == 1){
            return ha[x] == true ? 2 : 0;
        }
        int tot = 0;
        if(ha[x] == true)tot = 2;
        int cnt = 0;
        for(auto y: adj[x]){
            if(!vis[y]){
                cnt+=dfs(y, adj, ha, vis);
            }
        }
        if(cnt > 0)return cnt+2;
        return tot;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(auto &x: edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<bool> vis(n, false);
        int x = dfs(0, adj, hasApple, vis);
        return x > 0 ? x-2 : x;
    }
};