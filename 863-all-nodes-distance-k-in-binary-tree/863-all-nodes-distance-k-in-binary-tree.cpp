/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*>mp; //child -> par
    
    void dfs(TreeNode*root , TreeNode*par)
    {
        if(!root)
            return;
        mp[root]=par;
        dfs(root->left,root);
        dfs(root->right,root);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        dfs(root,NULL);
        vector<int>ans;
        queue<pair<TreeNode*,int>>q;
        unordered_map<TreeNode*,int>vis;
        q.push({target,0});
        vis[target]=1;
        while(!q.empty())
        {
            auto [node , dist] = q.front();
            q.pop();
            if(dist==k)
                ans.push_back(node->val);
            auto par = mp[node] , leftChild = node->left , rightChild = node->right;
            if(par and vis[par]==0)
            {
                q.push({par,dist+1});
                vis[par]=1;
            }
            if(leftChild and vis[leftChild]==0){
                q.push({leftChild,dist+1});
                vis[leftChild]=1;
            }
            if(rightChild and vis[rightChild]==0){
                q.push({rightChild , dist+1});
                vis[rightChild]=1;
            }
        }
        
        return ans;
    }
};