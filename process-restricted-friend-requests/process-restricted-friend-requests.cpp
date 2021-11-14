class DSU{
public:
    vector<int>par;
    
    DSU(int n){
        par.resize(n);
        for(int i=0; i<n; i++)
            par[i]=i;
    }
    
    void merge(int u, int v)
    {
        int parU=find(u);
        int parV=find(v);
        if(parU==parV)
            return;
        par[parV]=parU;
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
    vector<bool> friendRequests(int n, vector<vector<int>>& rest, vector<vector<int>>& req) 
    {
        DSU dsu(n);
        
        int m=req.size();
        vector<bool>ans(m,0);
        for(int i=0; i<m; i++)
        {
            int u=req[i][0] , v=req[i][1];
            
            DSU temp1 = dsu , temp2=dsu;
            temp1.merge(u,v);
            //temp2.merge(v,u);
            
            bool flag1 = true;
            //bool flag2=true;
            for(vector<int>& v : rest) {
                if(temp1.find(v[0]) == temp1.find(v[1])) {
                    flag1 = false;
                    break;
                }
                /*if(temp2.find(v[0])==temp2.find(v[1])){
                    flag2=false;
                    break;
                }*/
            }
            
            
            if(flag1) {
                ans[i] = true;
                dsu.merge(u,v);
            }
        }
        
        return ans;
        
    }
};