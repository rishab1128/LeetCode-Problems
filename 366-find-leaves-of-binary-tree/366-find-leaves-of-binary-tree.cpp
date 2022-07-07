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
    
    int dfs(TreeNode*root)
    {
        if(root and !root->left and !root->right)
        {
            mp[0].push_back(root->val);
            return 0;
        }
        int leftVal = root->left ? 1+dfs(root->left) : 0;
        int rightVal = root->right ? 1+dfs(root->right) : 0;
        
        mp[max(leftVal,rightVal)].push_back(root->val);
        
        return max(leftVal,rightVal);
    }
    
    vector<vector<int>> findLeaves(TreeNode* root) 
    {
        dfs(root);
        vector<vector<int>>ans;
        for(auto [key,vec]: mp)
            ans.push_back(vec);
        
        return ans;
        
    }
};