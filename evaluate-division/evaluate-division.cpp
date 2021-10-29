class Solution {
public:
    
    map< string , vector<pair<string,double>> > adj;

    double bfs(string&u , string&v)
    {
        queue<pair<string , double>>q;
        map<string,int>vis;
        q.push({u,1.0});
        vis[u]=1;
        while(!q.empty())
        {
            string node=q.front().first;
            double ans=q.front().second;
            q.pop();
            if(node==v)
                return ans;

            for(auto child : adj[node])
            {
                string childNode=child.first;
                double wt=child.second;
                if(!vis[childNode])
                {
                    vis[childNode]=1;
                    double newAns=ans*wt;
                    q.push({childNode , newAns});
                }

            }

        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& eqs, vector<double>& val, vector<vector<string>>& que) 
    {
        adj.clear();
        int n=eqs.size();
        for(int i=0; i<n; i++)
        {
            auto u=eqs[i][0] , v=eqs[i][1];
            double w=val[i] , w_dash=(1.0/w);
            adj[u].push_back({v,w});
            adj[v].push_back({u,w_dash});
        }
        int q=que.size();
        vector<double>ans(q);
        for(int i=0; i<q; i++)
        {
            auto u=que[i][0] , v=que[i][1];
            if(adj.find(u)==adj.end() || adj.find(v)==adj.end())
                ans[i]=-1.0;
            else
            {
                double res=bfs(u,v);
                ans[i]=res;
            }
        }
        return ans;
    }
};