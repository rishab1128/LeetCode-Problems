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
    vector<string>ans;
    
    void dfs(TreeNode*root, string str)
    {
        if(!root)
            return;
        
        if(!root->left and !root->right)
        {
            str+=to_string(root->val);
            ans.push_back(str);
            return;
        }
        dfs(root->left,str+to_string(root->val)+"->");
        dfs(root->right,str+to_string(root->val)+"->");
    }
    
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        dfs(root,"");
        return ans;
        
    }
};