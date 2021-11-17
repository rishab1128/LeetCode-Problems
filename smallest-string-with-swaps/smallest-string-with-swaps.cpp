class DSU
{
public:
    vector<int>par , rank;
    DSU(int n)
    {
        par.resize(n);
        rank.resize(n);
        for(int i=0; i<n; i++){
            par[i]=i;
            rank[i]=1;
        }
            
    }
    
    int find(int x)
    {
        if(x==par[x])
            return x;
        return par[x]=find(par[x]);
    }
    
    void merge(int x, int y)
    {
        int xset = find(x);
        int yset = find(y);
 
        if (xset == yset) //Both x & y belong to the same set
            return;
 
        
        if(rank[xset]>rank[yset])
        {
            par[yset]=xset;
            rank[xset]+=rank[yset];
        }
        else
        {
            par[xset]=yset;
            rank[yset]+=rank[xset];
        }
        
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) 
    {
        int n=s.size();
        DSU dsu(n);
        for(auto p : pairs)
        {
            int parU=dsu.find(p[0]) , parV=dsu.find(p[1]);
            if(parU!=parV)
                dsu.merge(p[0] , p[1]);
        }
        for(auto p : pairs)
        {
            int parU=dsu.find(p[0]) , parV=dsu.find(p[1]);
            if(parU!=parV)
                dsu.merge(p[0] , p[1]);
        }
        
        map<int , vector<int>>mp;
        for(int i=0; i<n; i++)
        {
            int u=dsu.par[i];
            //cout<<u<<" ";
            mp[u].push_back(i);
        }
        //cout<<endl;
        
        string ans(n,'*');
        for(auto x : mp)
        {
            int ele=x.first;
            string res="";
            for(auto idx : mp[ele])
                res+=s[idx];
            sort(res.begin(),res.end());
            int j=0;
            for(auto idx : mp[ele])
                ans[idx]=res[j++];
        }
        
        return ans;
        
        
        
    }
};