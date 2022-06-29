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
    vector<string>arr;
    
    void dfs(TreeNode*root, string s)
    {
        if(!root)
            return;
        if(root and !root->left and !root->right)
        {
            char ch = (char)root->val+'a';
            s+=ch;
            reverse(s.begin(),s.end());
            arr.push_back(s);
            return;
        }
        char ch = (char)root->val+'a';
        dfs(root->left,s+ch);
        dfs(root->right,s+ch);
    }
    
    string smallestFromLeaf(TreeNode* root) 
    {
        dfs(root,"");
        sort(arr.begin(),arr.end());
        return arr[0];
    }
};