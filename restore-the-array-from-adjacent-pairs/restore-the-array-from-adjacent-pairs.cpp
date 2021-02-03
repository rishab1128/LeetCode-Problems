class Solution {
public:
    
    Solution()
    {
        std::ios::sync_with_stdio(false);
    }
    
    map<int,vector<int>>adj;
    
    void dfs(int val,map<int,int>&vis,vector<int>&ans)
    {
        ans.push_back(val);
        vis[val]=1;
        for(auto x: adj[val])
        {
            if(!vis[x])
                dfs(x,vis,ans);
        }
    }

    vector<int> restoreArray(vector<vector<int>>& arr) 
    {
       map<int,int>deg,vis;
       vector<int>ans;
       int val=0;
       set<int>st;
       int n=arr.size();
       for(int i=0; i<n; i++)
       {
            adj[arr[i][0]].push_back(arr[i][1]);
            adj[arr[i][1]].push_back(arr[i][0]);
            deg[arr[i][0]]++;
            deg[arr[i][1]]++;
            st.insert(arr[i][0]);
            st.insert(arr[i][1]);
       }
    
       for(auto x: st)
       {
            if(deg[x]==1)
            {
                val=x;
                break;
            }
       }
       dfs(val,vis,ans);
       return ans;
    }

};