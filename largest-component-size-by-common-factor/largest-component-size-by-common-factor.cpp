class UnionFind
{
    vector<int>par;
public:
    UnionFind(int n){
        par.resize(n);
        for(int i=0; i<n; i++)
            par[i]=i;
    }
    int find(int x)
    {
        if(x==par[x])
            return x;
        return par[x]=find(par[x]);
    }
    void Union(int u, int v)
    {
        int pu=find(u) , pv=find(v);
        if(pu==pv)
            return;
        par[pu]=pv;
    }
};

class Solution {
public:
    
    vector<int>getPrimeFactors(int n)
    {
        vector<int>factors;
        for(int i=2; i*i<=n; i++)
        {
            if(n%i==0)
            {
                factors.push_back(i);
                while(n%i==0)
                    n/=i;
            }
        }
        if(n>1)
            factors.push_back(n);
        return factors;
    }
    
    int largestComponentSize(vector<int>& arr) 
    {
        UnionFind uf(1e5+1);
        for(int num : arr)
        {
            vector<int>primeFactors=getPrimeFactors(num);
            for(int primefactor : primeFactors)
                uf.Union(num,primefactor);
        }
        map<int,vector<int>>mp;
        for(int x: arr)
        {
            int parX=uf.find(x);
            mp[parX].push_back(x);
        }
        
        int ans=1;
        for(auto x: mp)
            ans=max(ans,(int)mp[x.first].size());
        
        return ans;
        
        
    }
};