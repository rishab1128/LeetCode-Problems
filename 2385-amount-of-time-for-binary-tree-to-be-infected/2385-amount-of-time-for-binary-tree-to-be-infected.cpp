/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void dfs(TreeNode*root , unordered_map<int,vector<int>>&adj)
    {
        if(!root)
            return;
        
        int node = root->val;
        if(root->left)
        {
            int nodeL = root->left->val;
            adj[node].push_back(nodeL);
            adj[nodeL].push_back(node);
        }
        if(root->right)
        {
            int nodeR = root->right->val;
            adj[node].push_back(nodeR);
            adj[nodeR].push_back(node);
        }
        
        dfs(root->left, adj);
        dfs(root->right, adj);
    }
    
    int amountOfTime(TreeNode* root, int start) 
    {
        unordered_map<int,vector<int>>adj;
        dfs(root,adj);
        queue<int>q;
        vector<bool>vis(1e5+1,0);
        q.push(start);
        vis[start] = 1;
        int ct = 0;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                int node = q.front();
                q.pop();
                for(auto child : adj[node])
                {
                    if(!vis[child])
                    {
                        vis[child] = 1;
                        q.push(child);
                    }
                }
            }
            ct++;
        }
        return ct-1;
        
    }
};