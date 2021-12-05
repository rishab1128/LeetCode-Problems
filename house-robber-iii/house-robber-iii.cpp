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
    map<pair<TreeNode*,int> , int>dp;
    void dfs(TreeNode*node)
    {
        if(node and !node->left  and !node->right)
        {
            dp[{node,0}]=0;
            dp[{node,1}]=node->val;
            return;
        }
        if(node->left and node->right)
        {
            dfs(node->left);
            dfs(node->right);
            dp[{node,0}]=max(dp[{node->left,0}] , dp[{node->left,1}])+max(dp[{node->right,0}] , dp[{node->right ,1}]);
            dp[{node,1}]=node->val + dp[{node->left,0}]+ dp[{node->right,0}];
        }
        else if(node->left)
        {
            dfs(node->left);
            dp[{node,0}]=max(dp[{node->left,0}] , dp[{node->left,1}]);
            dp[{node,1}]=node->val + dp[{node->left,0}];
        }
        else if(node->right)
        {
            dfs(node->right);
            dp[{node,0}]=max(dp[{node->right,0}] , dp[{node->right ,1}]);
            dp[{node,1}]=node->val + dp[{node->right,0}];
        }
    }
    
    int rob(TreeNode* root) {
        dp.clear();
        dfs(root);
        return max( dp[{root,0}] , dp[{root,1}] );
    }
};