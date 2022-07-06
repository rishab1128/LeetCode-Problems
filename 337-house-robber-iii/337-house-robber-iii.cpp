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
    map<pair<TreeNode*,int>,int>dp;
    int dfs(TreeNode*root, int flag)
    {
        if(!root)
            return 0;
        
        if(dp.count({root,flag}))
            return dp[{root,flag}];
        
        int ans = 0;
        if(flag)
            ans = root->val+dfs(root->left,flag^1)+dfs(root->right,flag^1);
        else
        {
            int op1 = dfs(root->left,flag^1)+dfs(root->right,flag^1);
            int op2 = dfs(root->left,flag^1)+dfs(root->right,flag);
            int op3 = dfs(root->left,flag)+dfs(root->right,flag^1);
            int op4 = dfs(root->left,flag)+dfs(root->right,flag);
            
            ans = max({op1,op2,op3,op4});
        }
            
        
        return dp[{root,flag}]=ans;
    }
    
    int rob(TreeNode* root) 
    {
        int ans1 = dfs(root,1); 
        int ans2 = dfs(root,0);
        return max(ans1,ans2);
    }
};