class Solution {
public:
    
    vector<vector<int>>adj;
    vector<int>diameter; //diameter[i] = what is the diameter if path passes through node i 
    vector<int>downPath; //downPath[i] = longest simple path in subtree rooted at i that starts at i
    
    void calDownPath(int node, int par)
    {
        int bestChildDownPath = 0;
        bool leaf = 1;
        for(auto child : adj[node])
        {
            if(child!=par)
            {
                leaf = 0;
                calDownPath(child,node);
                bestChildDownPath = max(bestChildDownPath , downPath[child]);
            }
        }
        if(leaf)
            downPath[node] = 0;
        else
            downPath[node]=1+bestChildDownPath;
    }
    
    void calDiameter(int node, int par)
    {
        
        vector<int>children;
        for(auto child :  adj[node])
        {
            if(child!=par)
            {
                calDiameter(child,node);
                children.push_back(downPath[child]);
            }
        }
        if(children.size()==0)
            diameter[node] = 0;
        else if(children.size()==1)
            diameter[node]=1+children[0];
        else
        {
            sort(children.rbegin(),children.rend());
            diameter[node] = 2+children[0]+children[1];
        }
    }
    
    
    int treeDiameter(vector<vector<int>>& edges) 
    {
        int n = edges.size()+1;
        
        adj.resize(n);
        diameter.resize(n,0);
        downPath.resize(n,0);
        
        for(auto edge : edges)
        {
            int u = edge[0] , v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        calDownPath(0,-1);
        
        // for(auto x: downPath)
        //     cout<<x<<" ";
        // cout<<endl;
        
        calDiameter(0,-1);
        
        // cout<<diameter[0]<<endl;
        
        return *max_element(diameter.begin(),diameter.end());
    }
};