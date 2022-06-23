class Solution {
public:
    
    void dfs(int root, unordered_map<int,vector<int>>&adj, vector<bool>&vis, int&ct)
    {
        ct++;
        vis[root]=1;
        for(auto node : adj[root])
        {
            if(!vis[node])
                dfs(node,adj,vis,ct);
        }
        return;
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) 
    {
        vector<int>indeg(n,0);
        int edges = 0;
        unordered_map<int,vector<int>>adj;
        for(int i=0; i<n; i++)
        {
            int node = i , left = leftChild[i] , right = rightChild[i];
            if(left!=-1)
                adj[node].push_back(left), indeg[left]++ , edges++;
            if(right!=-1)
                adj[node].push_back(right), indeg[right]++ , edges++;
        }
        
        if(edges!=n-1)
            return false;
        
        int root = -1;
        for(int i=0; i<n; i++)
        {
            if(!indeg[i])
            {
                root=i;
                break;
            }
        }
        
        vector<bool>vis(n,0);
        int ct = 0;
        dfs(root,adj,vis,ct);
        
        return ct==n;
    }
};