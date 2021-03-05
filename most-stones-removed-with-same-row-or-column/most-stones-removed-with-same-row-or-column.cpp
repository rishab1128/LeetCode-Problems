#include<bits/stdc++.h>
using namespace std;


class Solution 
{
public:
    Solution()
    {
        std::ios::sync_with_stdio(false);
        cin.tie(NULL);
    }
    //See side note bar
    //Using DFS  
     
    
    int dfs(unordered_map<int,vector<int>>&rows, unordered_map<int,vector<int>>&cols, unordered_set<int>&vis_rows, int row)
    {
        int ans=0;
        if(vis_rows.find(row)==vis_rows.end())
        {
            vis_rows.insert(row);
            ans+=rows[row].size();
            for(auto c: rows[row])
            {
                for(auto r: cols[c])
                    ans+=dfs(rows,cols,vis_rows,r);
            }
        }
        return ans;
       
    }
    
    int removeStones(vector<vector<int>>& stones) 
    {
        unordered_map<int,vector<int>>rows,cols;
        unordered_set<int>vis_rows;
        int ans=0;
        for(auto v: stones)
        {
            rows[v[0]].push_back(v[1]);
            cols[v[1]].push_back(v[0]);
        }
        for(auto row: rows)
        {
            ans+=max(0,dfs(rows,cols,vis_rows,row.first)-1);
        }
        return ans;
    }
};