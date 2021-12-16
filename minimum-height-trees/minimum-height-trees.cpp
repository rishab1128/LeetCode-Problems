//This approach is based on observing the fact that there can be a maximum of 2 MHTs and the node which yields the minimum-heighted tree is(are) the mid-point(s) of longest path in the given graph.

//Refer : https://leetcode.com/problems/minimum-height-trees/discuss/1631179/C%2B%2BPython-3-Simple-Solution-w-Explanation-or-Brute-Force-%2B-2x-DFS-%2B-Remove-Leaves-w-BFS

//Approach 1 : Using DFS to find the longest path and then ans=middle node of the longest path

class Solution {
public:
    unordered_map<int,vector<int>>adj;
    vector<int>vis;
    
    vector<int>dfs(int node)
    {
        // longestPath will hold longest path found, starting from any of adjacent nodes of i
        
        vis[node]=1; // mark as visited to avoid loop
        vector<int>path , longestPath;
        
        for(auto child : adj[node])
        {
            if(!vis[child])
            {
                path=dfs(child); // run DFS from each adjacent node to find longest path
                if(path.size()>longestPath.size())
                    longestPath=path;
            }
        }
        longestPath.push_back(node); // add i itself to longest path & we get the longest path starting at i
        vis[node]=0;
        return longestPath;
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) 
    {
        vis.resize(n,0);
        for(auto e : edges)
        {
            int u=e[0],v=e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>path=dfs(dfs(0)[0]);                // 1st DFS from arbitrary node(0 in this case) & another DFS from furthest node returned by 1st DFS
        int sz=path.size();
        if(sz%2)
            return {path[sz/2]};
        
        return {path[(sz/2)] , path[(sz/2)-1]};
    }
};