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
    int maxi;
    
    pair<int,int>dfs(TreeNode*root)
    {
        if(!root)
            return {0,0};
        if(root and !root->left and !root->right)
            return {0,0};
        int leftChild=root->left?1+dfs(root->left).second:0;
        int rightChild=root->right?1+dfs(root->right).first:0;
        maxi=max({maxi, leftChild , rightChild});
        return {leftChild , rightChild};
    }
    
    int longestZigZag(TreeNode* root)
    {
        maxi=0;
        dfs(root);
        return maxi;
    }
};