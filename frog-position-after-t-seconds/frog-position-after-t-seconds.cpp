class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int tim, int target) 
    {
        if(n==1)
            return 1.0;
        vector<int>adj[n+1];
        for(int i=0; i<(int)edges.size(); i++)
        {
            int u=edges[i][0],v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<tuple<int,double,int>>q;
        q.push(make_tuple(1,1.0,0));
        vector<int>vis(n+1,0);
        while(q.size()>0)
        {
            tuple t=q.front();
            q.pop();
            int node=get<0>(t);
            double prob=get<1>(t);
            int lvl=get<2>(t);
            vis[node]=1;
            //cout<<node<<" "<<prob<<" "<<lvl<<endl;
            if((node==target and tim==lvl) || (node==target and node!=1 and adj[node].size()==1 and tim>=lvl))
            {
                //cout<<node<<" "<<prob<<" "<<lvl<<endl;
                return prob;
            }
            int sz=adj[node].size();
            if(node!=1)
                sz-=1;
            for(auto child : adj[node])
            {
                if(!vis[child])
                {
                    double childProb=prob*(1/((double)sz));
                    int childLvl=lvl+1;
                    q.push(make_tuple(child,childProb,childLvl));
                }
            }
        }
        return 0.0;
    }
};