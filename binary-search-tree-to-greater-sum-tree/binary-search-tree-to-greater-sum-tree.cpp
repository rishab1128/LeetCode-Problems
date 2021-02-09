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
    void inorder(TreeNode*root, vector<int>&a)
    {
        if(root)
        {
            inorder(root->left,a);
            a.push_back(root->val);
            inorder(root->right,a);
        }
    }
    
    void func(TreeNode**root,map<int,int>&mp)
    {
        if(*root)
        {
            (*root)->val=mp[(*root)->val];
            func(&((*root)->left),mp);
            func(&((*root)->right),mp);
        }
    }
    
    TreeNode* bstToGst(TreeNode* root) 
    {
        vector<int>a;
        inorder(root,a);
        int n=a.size();
        map<int,int>mp;
        int suff[n];
        suff[n-1]=a[n-1];
        mp[a[n-1]]=suff[n-1];
        for(int i=n-2; i>=0; i--)
        {
            suff[i]=suff[i+1]+a[i];
            mp[a[i]]=suff[i];
        }
        func(&root,mp);
        return root;
    }
};