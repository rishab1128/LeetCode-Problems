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
    int ans;
    map<TreeNode*,int>dp;
    int subtreeSum(TreeNode*root)
    {
        if(!root)
            return 0;
        dp[root]=root->val+subtreeSum(root->left)+subtreeSum(root->right);
        return dp[root];
    }
    
    void dfs(TreeNode*root)
    {
        if(root)
        {
            if(root->left and root->right)
            {
                ans+=abs(dp[root->left]-dp[root->right]);
                dfs(root->left);
                dfs(root->right);
            }
            else if(root->left)
            {
                ans+=abs(dp[root->left]);
                dfs(root->left);
            }
            else if(root->right)
            {
                ans+=abs(dp[root->right]);
                dfs(root->right);
            }
            else
                ans+=0;
        }
    }
    
    int findTilt(TreeNode* root) 
    {
        dp.clear();
        ans=0;
        subtreeSum(root);
        dfs(root);
        return ans;
    }
};