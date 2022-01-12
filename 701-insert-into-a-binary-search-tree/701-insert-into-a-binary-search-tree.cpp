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
    void func(TreeNode**root , int val)
    {
        if(*root==NULL)
        {
            TreeNode*tmp=new TreeNode();
            tmp->val=val;
            tmp->left=tmp->right=NULL;
            *root=tmp;
        }
        TreeNode*tmp=(*root);
        if(val>tmp->val)
            func(&(tmp->right),val);
        if(val<tmp->val)
            func(&(tmp->left),val);
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) 
    {
        func(&root,val);
        return root;
    }
};