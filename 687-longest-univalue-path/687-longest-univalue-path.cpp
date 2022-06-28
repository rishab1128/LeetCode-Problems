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
    int dfs(TreeNode*root)
    {
        if(!root)
            return 0;
        
        int len1 = dfs(root->left);
        int len2 = dfs(root->right);
        
        int lt = 0 , rt = 0;
        if(root->left and root->left->val==root->val)
            lt += len1+1;
        if(root->right and root->right->val==root->val)
            rt += len2+1;
        
        ans = max(ans,lt+rt);
        return max(lt,rt);
    }
    
    int longestUnivaluePath(TreeNode* root) 
    {
        ans = 0;
        dfs(root);
        return ans;
        
    }
};