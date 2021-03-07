#include<bits/stdc++.h>
using namespace std;

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
            rank[i]=1;
        }
    }
 
    // Returns the parent/ set of the given item x
    int find(int x)
    {
        if(parent[x]==x)
            return x;
        return parent[x]=find(parent[x]);
    }
    
    //Merges two sets
    void Union(int x, int y)
    {
 
        int xset = find(x);
        int yset = find(y);
        // cout<<"child --> "<<x<<" and Parent --> "<<xset<<endl;
        // cout<<"child --> "<<y<<" and Parent --> "<<yset<<endl;
        // cout<<"----------------------------------------------"<<endl;
        if (xset == yset) //Both x & y belong to the same set
            return;
 
        //Assuming rank/size of x is always less than that of y
        if(rank[xset]>rank[yset])
            swap(xset,yset);
        
        parent[xset]=yset;
        rank[yset]+=rank[xset];
        // cout<<"Parent Vector : "<<endl;
        // for(int i=0; i<n; i++)
        //     cout<<parent[i]<<" ";
        // cout<<endl;
        // cout<<"----------------------------------------"<<endl;
    }
    
    int sizee(int i)
    {
        return rank[i];
    }
    
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int n=nums.size() , ans=0;
        DisjointSet obj(n);
        unordered_map<int,int>mp;
        for(int i=0; i<n; i++)
        {
            if(mp.find(nums[i])!=mp.end())
                continue;
            int x=nums[i]-1 , y=nums[i]+1 ;
            if(mp.find(x)!=mp.end())
                obj.Union(i,mp[x]);
            if(mp.find(y)!=mp.end())
                obj.Union(i,mp[y]);
            mp[nums[i]]=i;
        }
        for(int i=0; i<n; i++)
        {
            //cout<<obj.sizee(i)<<" ";
            ans=max(ans,obj.sizee(i));
        }
        // cout<<endl;
        // for(int i=0; i<n; i++)
        // {
        //     cout<<obj.find(i)<<" ";
        // }
        
        return ans;
    }
};