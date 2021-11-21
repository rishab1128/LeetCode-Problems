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
    unordered_map<int,int>mp;
    
    TreeNode*build(vector<int>&post , int left , int right , int&i)
    {
        if((left>right) || (i<0))
            return NULL;
        
        int idx=mp[post[i]];
        
        TreeNode*root=new TreeNode(post[i--]);
        root->right=build(post, idx+1 , right,i);
        root->left=build(post, left, idx-1, i);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& post) 
    {
        int n=inorder.size();
        for(int i=0; i<n; i++)
            mp[inorder[i]]=i;
        int i=n-1;
        TreeNode*ans=build(post,0,n-1,i);
        return ans;
    }
};