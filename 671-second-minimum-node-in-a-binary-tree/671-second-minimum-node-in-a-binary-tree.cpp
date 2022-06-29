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
    
    int mini;
    long long ans = LLONG_MAX;
    
    void dfs(TreeNode*root)
    {
        if(!root)
            return;
        
        if(mini<root->val and root->val<ans)
            ans=root->val;
        else if(mini==root->val)
        {
            dfs(root->left);
            dfs(root->right);
        }
            
    }
    
    
    int findSecondMinimumValue(TreeNode* root) 
    {
        mini=root->val;
        dfs(root);
        return ans!=LLONG_MAX ? ans  : -1;
    }
};