class TreeAncestor {
public:
    int n;
    vector<int>adj[50001];
    int up[50001][20]; //up[node][i] := stores the 2^i ancestor of node 
    void calcUp(int node , int par)
    {
        up[node][0]=par;
        for(int i=1; i<20; i++)
        {
            if(up[node][i-1]!=-1)
                up[node][i]=up[up[node][i-1]][i-1];
            else
                up[node][i]=-1;
        }
        
        for(auto child : adj[node])
        {
            if(child!=par)
                calcUp(child,node);
        }
    }
    
    TreeAncestor(int N, vector<int>& par) 
    {
        n=N;
        for(int i=0; i<n; i++)
        {
            int u=par[i],v=i;
            if(u!=-1)
            {
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        calcUp(0,-1);
    }
    
    int getKthAncestor(int node, int k) 
    {
        for(int i = 19; i >= 0; i--)
        { 
		    int num = (1<<i);
            if(k >= num)
            {        
                node = up[node][i];
				k -= num;         
                if(node == -1) return -1;				
            }
        }

        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->ans_query(node,k);
 */