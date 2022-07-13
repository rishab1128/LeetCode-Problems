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
    map<int,vector<int>>mp;
    
    void bfs(TreeNode*root,int dir)
    {
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty())
        {
            auto [node,dir] = q.front();
            q.pop();
            mp[dir].push_back(node->val);
            if(node->left)
                q.push({node->left,dir-1});
            if(node->right)
                q.push({node->right,dir+1});
        }
    }
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        
        if(!root)
            return {};
        
        bfs(root,0);
        vector<vector<int>>ans;
        
        for(auto [ele,vec] : mp)
            ans.push_back(vec);
        
        return ans;
    }
};