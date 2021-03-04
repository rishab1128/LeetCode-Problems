#include<bits/stdc++.h>
using namespace std;

class DisjointSet
{
    int *rank, *parent, n;
 
public:
    DisjointSet(int n)
    {
        rank = new int[n];
        parent = new int[n];
        this->n = n;
        makeSet();
    }
 
    void makeSet()
    {
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    
    // Returns the parent/ set of the given item x
    int find(int x)
    {
        if (parent[x] != x)
        {
 
            parent[x] = find(parent[x]);
        }
 
        return parent[x];
    }
    
    //Merges two sets
    void Union(int x, int y)
    {
 
        int xset = find(x);
        int yset = find(y);
 
        if (xset == yset) 
            return;
 
        if (rank[xset] < rank[yset])
        {
            parent[xset] = yset;
        }
        else if (rank[xset] > rank[yset])
        {
            parent[yset] = xset;
        }
 
        else
        {
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& arr) 
    {
        int n=arr.size();
        DisjointSet obj(n);
        map<int,int>mp;
        int ct=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i!=j&&arr[i][j]==1&&obj.find(i)!=obj.find(j))
                    obj.Union(i,j);
            }
        }
        for(int i=0; i<n; i++)
        {
            if(!mp[obj.find(i)])
            {
                ct++;
                mp[obj.find(i)]=1;
            }
        }
        return ct;
        
    }
};