class LockingTree {
public:
    
    map<int,vector<int>>adj;
    map<int,vector<int>>ances;
    map<int,vector<int>>desc;
    map<int,int>locked;
    int n;

    void dfs(int node , int par)
    {
        if(par!=-1){
            ances[node].push_back(par);
            for(auto ele: ances[par])
                ances[node].push_back(ele);
        }

        for(auto child: adj[node])
        {
            if(child!=par)
            {
                dfs(child,node);
                desc[node].push_back(child);
                for(auto ele: desc[child])
                    desc[node].push_back(ele);
            }
        }
    }

    LockingTree(vector<int>& par) 
    {
        n=par.size();
        for(int i=0; i<n; i++)
        {
            adj[par[i]].push_back(i);
            adj[i].push_back(par[i]);
        }
        dfs(0,-1);
    }
    
    bool lock(int num, int user) 
    {
        if(locked[num]!=0)
            return false;
        locked[num]=user;
        return true;
            
    }
    
    bool unlock(int num, int user) 
    {
        if(locked[num]!=user) 
            return false;
        locked[num] = 0;
        return true;
    }
    
    bool upgrade(int num, int user) 
    {
        if(locked[num]==0)
        {
            int lockedDesc=0,lockedAnces=0;
            for(auto ele : desc[num])
            {
                if(locked[ele])
                    lockedDesc++;
            }
            for(auto ele : ances[num])
            {
                if(locked[ele])
                    lockedAnces++;
            }
            
            if(lockedDesc>=1 and lockedAnces==0)
            {
                locked[num]=user;
                for(auto ele : desc[num]){
                    locked[ele]=0;
                }
                return true;
            }
            else
                return false;
        }
        return false;
        
        
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */