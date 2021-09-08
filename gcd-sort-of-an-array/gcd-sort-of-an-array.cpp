class UnionFind
{
    vector<int>parent;
public:
    UnionFind(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int Find(int x)
    {
        if(x==parent[x])
            return x;
        return parent[x]=Find(parent[x]);
    }
    void Union(int u , int v)
    {
        int parU=Find(u),parV=Find(v);
        if(parU==parV)
            return;
        else
            parent[parU]=parV;
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
    
    bool gcdSort(vector<int>& arr) 
    {
        UnionFind uf(1e5+1);
        for(int num : arr)
        {
            vector<int>primeFactors=getPrimeFactors(num);
            for(int primefactor : primeFactors)
            {
                uf.Union(num,primefactor);
                //cout<<primefactor<<" ";
            }
            //cout<<endl;
        }
        
        vector<int>sortedArr(arr);
        sort(sortedArr.begin() , sortedArr.end());
        
        for(int i=0; i<arr.size(); i++)
        {
            if(uf.Find(arr[i])!=uf.Find(sortedArr[i]))
                return false;
        }
        return true;
    }
};