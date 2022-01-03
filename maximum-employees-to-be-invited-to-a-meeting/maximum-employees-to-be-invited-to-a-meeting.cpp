//Refer : https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/discuss/1661433/C%2B%2B-Topo-Sort-%2B-Disjoint-Union
class DSU{

public :
    vector<int>par;
    vector<int>rank;
    
    DSU(int n){
        par.resize(n);
        rank.resize(n,1);
        for(int i=0; i<n; i++)
            par[i]=i;
    }
    
    void merge(int x , int y) //Using Union By Rank
    {
        int xset = find(x);
        int yset = find(y);
 
        if (xset == yset) 
            return;
 
        if (rank[xset] < rank[yset])
        {
            par[xset] = yset;
            rank[yset]+=rank[xset];
        }
        else
        {
            par[yset] = xset;
            rank[xset]+=rank[yset];
        }
    }
    
    int find(int u)
    {
        if(u==par[u])
            return u;
        return par[u]=find(par[u]);
    }

};

class Solution {
public:
    int maximumInvitations(vector<int>& adj) 
    {
        int n=adj.size();
        DSU dsu(n);
        vector<int>indeg(n,0);
        for(int i=0; i<n; i++)
            indeg[adj[i]]++;
        
        queue<int>q;
        vector<int>len(n,1);
        for(int i=0; i<n; i++)
        {
            if(indeg[i]==0)
                q.push(i);
        }
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            int neigh=adj[node];
            len[neigh]=max(len[neigh] , len[node]+1);
            indeg[neigh]--;
            if(indeg[neigh]==0)
                q.push(neigh);
        }
        
        for(int i=0; i<n; i++)
        {
            if(indeg[i])
                dsu.merge(i,adj[i]);
        }
        
        int join=0 , maxCycleLen=0;
        
        for(int i=0; i<n; i++)
        {
            if(!indeg[i])
                continue;
            int parent=dsu.find(i);
            int cycleLen=dsu.rank[parent];
            if(cycleLen==2)
            {
                int node=i , neigh=adj[node];
                indeg[neigh]--;
                join+=len[node]+len[neigh];
            }
            else
                maxCycleLen=max(maxCycleLen , cycleLen);
        }
        
        return max(join , maxCycleLen);
        
    }
};